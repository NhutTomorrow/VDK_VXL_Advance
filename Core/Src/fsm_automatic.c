/*
 * traffic_light.c
 *
 *  Created on: Sep 26, 2025
 *      Author: ASUS
 */

#include <fsm_automatic.h>
#include "global.h"
#include "lcd_display.h"
#include "led_display.h"
#include "input_reading.h"
#include "input_processing.h"
#include "fsm_manual.h"


#define LED_RED 0
#define LED_GREEN 1
#define LED_YELLOW 2

void traffic_light_automatic(){

	if (sys_state != AUTOMATIC_MODE) return;

	switch (auto_state) {
	        case INIT_AUTO:
	            // SỬA: Nạp đúng thời gian ban đầu (Đỏ 1 - Xanh 2)
	            time_road1 = time_red1;
	            time_road2 = time_gre2;

	            set_rgy1(LED_RED); // Đỏ 1
	            set_rgy2(LED_GREEN); // Xanh 2

	            auto_state = RED1_GRE2_AUTO;

	            setTimer(0, time_gre2 * 1000); // Timer chuyển state
	            setTimer(1, 1000);             // Timer đếm lùi 1s
	            break;

	        case RED1_GRE2_AUTO:
	            set_rgy1(LED_RED); // Đỏ 1
	            set_rgy2(LED_GREEN); // Xanh 2

	            // Xử lý đếm lùi và hiển thị mỗi 1 giây
	            if (isFlag(1)) {
	                time_road1--;
	                time_road2--;
	                display_auto_mode(); // Chỉ cập nhật LCD khi số thay đổi
	                setTimer(1, 1000);
	            }

	            // Chuyển trạng thái
	            if (isFlag(0) == 1) {
	                auto_state = RED1_YEL2_AUTO;

	                // QUAN TRỌNG: Nạp thời gian cho state kế tiếp
	                // Bên 1 còn Đỏ (phần dư = thời gian vàng bên 2), Bên 2 là Vàng
	                time_road1 = time_yel2;
	                time_road2 = time_yel2;

	                setTimer(0, time_yel2 * 1000);
	                display_auto_mode(); // Cập nhật màn hình ngay lập tức khi đổi state
	            }
	            break;

	        case RED1_YEL2_AUTO:
	            set_rgy1(LED_RED); // Đỏ 1
	            set_rgy2(LED_YELLOW); // Vàng 2

	            if (isFlag(1)) {
	                time_road1--;
	                time_road2--;
	                display_auto_mode();
	                setTimer(1, 1000);
	            }

	            if (isFlag(0) == 1) {
	                auto_state = GRE1_RED2_AUTO;

	                // QUAN TRỌNG: Nạp thời gian cho state kế tiếp (Xanh 1 - Đỏ 2)
	                time_road1 = time_gre1;
	                time_road2 = time_red2;

	                setTimer(0, time_gre1 * 1000);
	                display_auto_mode();
	            }
	            break;

	        case GRE1_RED2_AUTO:
	            set_rgy1(LED_GREEN); // Xanh 1
	            set_rgy2(LED_RED); // Đỏ 2

	            if (isFlag(1)) {
	                time_road1--;
	                time_road2--;
	                display_auto_mode();
	                setTimer(1, 1000);
	            }

	            if (isFlag(0) == 1) {
	                auto_state = YEL1_RED2_AUTO;

	                // QUAN TRỌNG: Nạp thời gian cho state kế tiếp (Vàng 1 - Đỏ 2)
	                time_road1 = time_yel1;
	                time_road2 = time_yel1;

	                setTimer(0, time_yel1 * 1000);
	                display_auto_mode();
	            }
	            break;

	        case YEL1_RED2_AUTO:
	            set_rgy1(LED_YELLOW); // Vàng 1
	            set_rgy2(LED_RED); // Đỏ 2

	            if (isFlag(1)) {
	                time_road1--;
	                time_road2--;
	                display_auto_mode();
	                setTimer(1, 1000);
	            }

	            if (isFlag(0) == 1) {
	                auto_state = RED1_GRE2_AUTO;

	                // Quay lại vòng lặp: Đỏ 1 - Xanh 2
	                time_road1 = time_red1;
	                time_road2 = time_gre2;

	                setTimer(0, time_gre2 * 1000);
	                display_auto_mode();
	            }
	            break;

	        default:
	            auto_state = RED1_GRE2_AUTO;
	            break;
	    }

	    // Nút nhấn chuyển mode
	// Code nằm trong traffic_light_automatic() hoặc hàm xử lý nút nhấn chung

	if (isSinglePressed(2)) {
	        sys_state = MANUAL_MODE;

	        switch (auto_state) {
	            // TRƯỜNG HỢP 1: Đang là Đỏ 1 - Xanh 2
	            // -> GIỮ NGUYÊN trạng thái này, không chuyển sang Vàng nữa
	            case RED1_GRE2_AUTO:
	                manual_state = RED1_GRE2;
	                // Không setTimer(4) vì trạng thái này là đứng yên mãi mãi
	                break;

	            // TRƯỜNG HỢP 2: Đang là Vàng 2 (Đang lở dở)
	            // -> Cho chạy nốt đèn Vàng rồi tự về Xanh 1 - Đỏ 2
	            case RED1_YEL2_AUTO:
	                manual_state = RED1_YEL2;
	                // Lấy thời gian còn lại hoặc set lại 3s để an toàn
	                setTimer(4, 3000);
	                break;

	            // TRƯỜNG HỢP 3: Đang là Xanh 1 - Đỏ 2
	            // -> GIỮ NGUYÊN trạng thái này
	            case GRE1_RED2_AUTO:
	                manual_state = GRE1_RED2;
	                // Không setTimer(4)
	                break;

	            // TRƯỜNG HỢP 4: Đang là Vàng 1 (Đang lở dở)
	            case YEL1_RED2_AUTO:
	                manual_state = YEL1_RED2;
	                setTimer(4, 3000);
	                break;

	            default:
	                manual_state = RED1_GRE2;
	                break;
	        }

	        // Cập nhật hiển thị ngay lập tức
	        display_manual_mode();

	        // Quan trọng: Phải gọi hàm set đèn ngay lập tức để không bị tắt đèn trong 1 chu kỳ quét
	        // (Tùy chọn, nhưng nên có để mượt hơn)

	    }
}







