#include <msp430.h>
#include <stdint.h>
/* Register */
const uint8_t _PEDOMETER3_REG_MANUFACTURING_ID      = 0x00;
const uint8_t _PEDOMETER3_REG_PART_ID               = 0x01;
const uint8_t _PEDOMETER3_REG_X_AXIS_HIGH_PASS_LOW  = 0x02;
const uint8_t _PEDOMETER3_REG_X_AXIS_HIGH_PASS_HIGH = 0x03;
const uint8_t _PEDOMETER3_REG_Y_AXIS_HIGH_PASS_LOW  = 0x04;
const uint8_t _PEDOMETER3_REG_Y_AXIS_HIGH_PASS_HIGH = 0x05;
const uint8_t _PEDOMETER3_REG_Z_AXIS_HIGH_PASS_LOW  = 0x06;
const uint8_t _PEDOMETER3_REG_Z_AXIS_HIGH_PASS_HIGH = 0x07;
const uint8_t _PEDOMETER3_REG_X_AXIS_OUTPUT_LOW     = 0x08;
const uint8_t _PEDOMETER3_REG_X_AXIS_OUTPUT_HIGH    = 0x09;
const uint8_t _PEDOMETER3_REG_Y_AXIS_OUTPUT_LOW     = 0x0A;
const uint8_t _PEDOMETER3_REG_Y_AXIS_OUTPUT_HIGH    = 0x0B;
const uint8_t _PEDOMETER3_REG_Z_AXIS_OUTPUT_LOW     = 0x0C;
const uint8_t _PEDOMETER3_REG_Z_AXIS_OUTPUT_HIGH    = 0x0D;
const uint8_t _PEDOMETER3_REG_PAD_STEP_LOW          = 0x0E;
const uint8_t _PEDOMETER3_REG_PAD_STEP_HIGH         = 0x0F;
const uint8_t _PEDOMETER3_REG_COMMAND_TEST_RESPONSE = 0x10;
const uint8_t _PEDOMETER3_REG_WHO_AM_I              = 0x11;
const uint8_t _PEDOMETER3_REG_CURRENT_TILT_POSITION = 0x12;
const uint8_t _PEDOMETER3_REG_PREVIOUS_TILT_POSITION = 0x13;
const uint8_t _PEDOMETER3_REG_INS1                  = 0x14;
const uint8_t _PEDOMETER3_REG_INS2                  = 0x15;
const uint8_t _PEDOMETER3_REG_INS3                  = 0x16;
const uint8_t _PEDOMETER3_REG_STATUS                = 0x17;
const uint8_t _PEDOMETER3_REG_INT_REL               = 0x19;
const uint8_t _PEDOMETER3_REG_CONTROL_1             = 0x1A;
const uint8_t _PEDOMETER3_REG_CONTROL_2             = 0x1B;
const uint8_t _PEDOMETER3_REG_CONTROL_3             = 0x1C;
const uint8_t _PEDOMETER3_REG_CONTROL_4             = 0x1D;
const uint8_t _PEDOMETER3_REG_CONTROL_5             = 0x1E;
const uint8_t _PEDOMETER3_REG_OUTPUT_DATA_CONTROL   = 0x1F;
const uint8_t _PEDOMETER3_REG_INTERRUPT_CONTROL_1   = 0x20;
const uint8_t _PEDOMETER3_REG_INTERRUPT_CONTROL_2   = 0x21;
const uint8_t _PEDOMETER3_REG_INTERRUPT_CONTROL_3   = 0x22;
const uint8_t _PEDOMETER3_REG_INTERRUPT_CONTROL_4   = 0x23;
const uint8_t _PEDOMETER3_REG_INTERRUPT_CONTROL_5   = 0x24;
const uint8_t _PEDOMETER3_REG_INTERRUPT_CONTROL_6   = 0x25;
const uint8_t _PEDOMETER3_REG_INTERRUPT_CONTROL_7   = 0x26;
const uint8_t _PEDOMETER3_REG_TILT_TIMER            = 0x27;
const uint8_t _PEDOMETER3_REG_TAP_REPORT_CONTROL    = 0x28;
const uint8_t _PEDOMETER3_REG_DOUBLE_TAP_EVENT      = 0x29;
const uint8_t _PEDOMETER3_REG_TAP_THRESHOLD_HIGH    = 0x2A;
const uint8_t _PEDOMETER3_REG_TAP_THRESHOLD_LOW     = 0x2B;
const uint8_t _PEDOMETER3_REG_FTD                   = 0x2C;
const uint8_t _PEDOMETER3_REG_STD                   = 0x2D;
const uint8_t _PEDOMETER3_REG_TLT                   = 0x2E;
const uint8_t _PEDOMETER3_REG_TWS                   = 0x2F;
const uint8_t _PEDOMETER3_REG_FREE_FALL_THRESHOLD   = 0x30;
const uint8_t _PEDOMETER3_REG_FREE_FALL_COUNTER     = 0x31;
const uint8_t _PEDOMETER3_REG_FREE_FALL_CONTROL     = 0x32;
const uint8_t _PEDOMETER3_REG_TILT_ANGLE_LL         = 0x34;
const uint8_t _PEDOMETER3_REG_TILT_ANGLE_HL         = 0x35;
const uint8_t _PEDOMETER3_REG_HYSTERESIS_SET        = 0x36;
const uint8_t _PEDOMETER3_REG_LOW_POWER_CONTROL     = 0x37;
const uint8_t _PEDOMETER3_REG_WUFTH                 = 0x3C;
const uint8_t _PEDOMETER3_REG_BTSWUFTH              = 0x3D;
const uint8_t _PEDOMETER3_REG_BTSTH                 = 0x3E;
const uint8_t _PEDOMETER3_REG_BTS_MOTION_DETECTION  = 0x3F;
const uint8_t _PEDOMETER3_REG_WUF_MOTION_DETECTION  = 0x40;
const uint8_t _PEDOMETER3_REG_PED_STPWM_LOW         = 0x41;
const uint8_t _PEDOMETER3_REG_PED_STPWM_HIGH        = 0x42;
const uint8_t _PEDOMETER3_REG_PEDOMETER_CONTROL_1   = 0x43;
const uint8_t _PEDOMETER3_REG_PEDOMETER_CONTROL_2   = 0x44;
const uint8_t _PEDOMETER3_REG_PEDOMETER_CONTROL_3   = 0x45;
const uint8_t _PEDOMETER3_REG_PEDOMETER_CONTROL_4   = 0x46;
const uint8_t _PEDOMETER3_REG_PEDOMETER_CONTROL_5   = 0x47;
const uint8_t _PEDOMETER3_REG_PEDOMETER_CONTROL_6   = 0x48;
const uint8_t _PEDOMETER3_REG_PEDOMETER_CONTROL_7   = 0x49;
const uint8_t _PEDOMETER3_REG_PEDOMETER_CONTROL_8   = 0x4A;
const uint8_t _PEDOMETER3_REG_PEDOMETER_CONTROL_9   = 0x4B;
const uint8_t _PEDOMETER3_REG_PEDOMETER_CONTROL_10  = 0x4C;
const uint8_t _PEDOMETER3_REG_SELF_TEST             = 0x4D;
const uint8_t _PEDOMETER3_REG_BUFFER_CONTROL_1      = 0x5A;
const uint8_t _PEDOMETER3_REG_BUFFER_CONTROL_2      = 0x5B;
const uint8_t _PEDOMETER3_REG_BUFFER_STATUS_1       = 0x5C;
const uint8_t _PEDOMETER3_REG_BUFFER_STATUS_2       = 0x5D;
const uint8_t _PEDOMETER3_REG_BUFFER_CLEAR          = 0x5E;
const uint8_t _PEDOMETER3_REG_BUFFER_READ           = 0x5F;


/* Tilt Position Registers (R)*/
const uint8_t _PEDOMETER3_POSITON_BIT_LEFT_X_NEGATIVE        = 0x20;
const uint8_t _PEDOMETER3_POSITON_BIT_RIGHT_X_POSITIVE       = 0x10;
const uint8_t _PEDOMETER3_POSITON_BIT_DOWN_Y_NEGATIVE        = 0x08;
const uint8_t _PEDOMETER3_POSITON_BIT_UP_Y_POSITIVE          = 0x04;
const uint8_t _PEDOMETER3_POSITON_BIT_FACE_DOWN_Y_NEGATIVE   = 0x02;
const uint8_t _PEDOMETER3_POSITON_BIT_FACE_UP_Y_POSITIVE     = 0x01;

/* Interrupt Source Registers (R)*/
/* INS 1 */
const uint8_t _PEDOMETER3_INS1_STPOVI  = 0x80;
const uint8_t _PEDOMETER3_INS1_STPWMI  = 0x40;
const uint8_t _PEDOMETER3_INS1_TLE     = 0x20;
const uint8_t _PEDOMETER3_INS1_TRI     = 0x10;
const uint8_t _PEDOMETER3_INS1_TDO     = 0x08;
const uint8_t _PEDOMETER3_INS1_TUO     = 0x04;
const uint8_t _PEDOMETER3_INS1_TFD     = 0x02;
const uint8_t _PEDOMETER3_INS1_TFU     = 0x01;
/* INS 2 */
const uint8_t _PEDOMETER3_INS2_FFS                = 0x80;
const uint8_t _PEDOMETER3_INS2_BFI                = 0x40;
const uint8_t _PEDOMETER3_INS2_WMI                = 0x20;
const uint8_t _PEDOMETER3_INS2_DRDY               = 0x10;
const uint8_t _PEDOMETER3_INS2_TDTS_NO_TAP        = 0x00;
const uint8_t _PEDOMETER3_INS2_TDTS_SINGLE_TAP    = 0x04;
const uint8_t _PEDOMETER3_INS2_TDTS_DOUBLE_TAP    = 0x08;
const uint8_t _PEDOMETER3_INS2_STPINCI            = 0x02;
const uint8_t _PEDOMETER3_INS2_TPS                = 0x01;
/* INS 3 */
const uint8_t _PEDOMETER3_INS3_WUFS    = 0x80;
const uint8_t _PEDOMETER3_INS3_BTS     = 0x40;
const uint8_t _PEDOMETER3_INS3_XNWU    = 0x20;
const uint8_t _PEDOMETER3_INS3_XPWU    = 0x10;
const uint8_t _PEDOMETER3_INS3_YNWU    = 0x08;
const uint8_t _PEDOMETER3_INS3_YPWU    = 0x04;
const uint8_t _PEDOMETER3_INS3_ZNWU    = 0x02;
const uint8_t _PEDOMETER3_INS3_ZPWU    = 0x01;

/* Status (STAT) (R)*/
const uint8_t _PEDOMETER3_STATUS_NO_INT         = 0x00;
const uint8_t _PEDOMETER3_STATUS_INT_ACTIVE     = 0x10;
const uint8_t _PEDOMETER3_STATUS_BACK_TO_SLEEP  = 0x00;
const uint8_t _PEDOMETER3_STATUS_WAKE_UP        = 0x01;

/* Control register 1 (CNTL1)(RW)*/
const uint8_t _PEDOMETER3_CNTL1_MODE_STAND_BY   = 0x00;
const uint8_t _PEDOMETER3_CNTL1_MODE_LOW_POWER  = 0x80;
const uint8_t _PEDOMETER3_CNTL1_RES_MODE_HIGHER_NOISE   = 0x00;
const uint8_t _PEDOMETER3_CNTL1_RES_MODE_LOWER_NOISE    = 0x40;
const uint8_t _PEDOMETER3_CNTL1_DATA_READY_DISABLE      = 0x00;
const uint8_t _PEDOMETER3_CNTL1_DATA_READY_ENABLE       = 0x20;
const uint8_t _PEDOMETER3_CNTL1_G_RANGE_2g              = 0x00;
const uint8_t _PEDOMETER3_CNTL1_G_RANGE_4g              = 0x08;
const uint8_t _PEDOMETER3_CNTL1_G_RANGE_8g              = 0x10;
const uint8_t _PEDOMETER3_CNTL1_TAP_DISABLE             = 0x00;
const uint8_t _PEDOMETER3_CNTL1_TAP_ENABLE              = 0x04;
const uint8_t _PEDOMETER3_CNTL1_PEDOMETER_DISABLE       = 0x00;
const uint8_t _PEDOMETER3_CNTL1_PEDOMETER_ENABLE        = 0x02;
const uint8_t _PEDOMETER3_CNTL1_TILT_DISABLE            = 0x00;
const uint8_t _PEDOMETER3_CNTL1_TILT_ENABLE             = 0x01;

/* Control register 2 */
const uint8_t _PEDOMETER3_CNTL2_SOFTWARE_RESET_ACTIVE      = 0x80;
const uint8_t _PEDOMETER3_CNTL2_SOFTWARE_RESET_NO_ACTIVE   = 0x00;
const uint8_t _PEDOMETER3_CNTL2_COMMAND_TEST_ACTIVE        = 0x40;
const uint8_t _PEDOMETER3_CNTL2_COMMAND_TEST_NO_ACTIVE     = 0x00;
const uint8_t _PEDOMETER3_CNTL2_LEFT_STATE_ENABLE          = 0x20;
const uint8_t _PEDOMETER3_CNTL2_RIGHT_STATE_ENABLE         = 0x10;
const uint8_t _PEDOMETER3_CNTL2_DOWN_STATE_ENABLE          = 0x08;
const uint8_t _PEDOMETER3_CNTL2_UP_STATE_ENABLE            = 0x04;
const uint8_t _PEDOMETER3_CNTL2_FACE_DOWN_STATE_ENABLE     = 0x02;
const uint8_t _PEDOMETER3_CNTL2_FACE_UP_STATE_ENABLE       = 0x01;

/* Control register 3 */
const uint8_t _PEDOMETER3_CNTL3_OTP_OUTPUT_DATA_RATE_1_563Hz   = 0x00;
const uint8_t _PEDOMETER3_CNTL3_OTP_OUTPUT_DATA_RATE_6_25Hz    = 0x40;
const uint8_t _PEDOMETER3_CNTL3_OTP_OUTPUT_DATA_RATE_12_5Hz    = 0x80;  // Def
const uint8_t _PEDOMETER3_CNTL3_OTP_OUTPUT_DATA_RATE_50Hz      = 0xC0;
const uint8_t _PEDOMETER3_CNTL3_TAP_OUTPUT_DATA_RATE_50Hz      = 0x00;
const uint8_t _PEDOMETER3_CNTL3_TAP_OUTPUT_DATA_RATE_100Hz     = 0x08;
const uint8_t _PEDOMETER3_CNTL3_TAP_OUTPUT_DATA_RATE_200Hz     = 0x10;
const uint8_t _PEDOMETER3_CNTL3_TAP_OUTPUT_DATA_RATE_400Hz     = 0x18; // Def
const uint8_t _PEDOMETER3_CNTL3_TAP_OUTPUT_DATA_RATE_12_5Hz    = 0x20;
const uint8_t _PEDOMETER3_CNTL3_TAP_OUTPUT_DATA_RATE_25Hz      = 0x28;
const uint8_t _PEDOMETER3_CNTL3_TAP_OUTPUT_DATA_RATE_800Hz     = 0x30;
const uint8_t _PEDOMETER3_CNTL3_TAP_OUTPUT_DATA_RATE_1600Hz    = 0x38;
const uint8_t _PEDOMETER3_CNTL3_OWUF_OUTPUT_DATA_RATE_0_781Hz  = 0x00; // Def
const uint8_t _PEDOMETER3_CNTL3_OWUF_OUTPUT_DATA_RATE_1_563Hz  = 0x01;
const uint8_t _PEDOMETER3_CNTL3_OWUF_OUTPUT_DATA_RATE_3_125Hz  = 0x02;
const uint8_t _PEDOMETER3_CNTL3_OWUF_OUTPUT_DATA_RATE_6_250Hz  = 0x03;
const uint8_t _PEDOMETER3_CNTL3_OWUF_OUTPUT_DATA_RATE_12_5Hz   = 0x04;
const uint8_t _PEDOMETER3_CNTL3_OWUF_OUTPUT_DATA_RATE_25Hz     = 0x05;
const uint8_t _PEDOMETER3_CNTL3_OWUF_OUTPUT_DATA_RATE_50Hz     = 0x06;
const uint8_t _PEDOMETER3_CNTL3_OWUF_OUTPUT_DATA_RATE_100Hz    = 0x07;

/* Control register 4 */
const uint8_t _PEDOMETER3_CNTL4_COUNTER_CLEAR_MODE              = 0x00;
const uint8_t _PEDOMETER3_CNTL4_COUNTER_DECREMENT_MODE          = 0x80;
const uint8_t _PEDOMETER3_CNTL4_THRESHOLD_MODE_ABSOLUTE         = 0x00;
const uint8_t _PEDOMETER3_CNTL4_THRESHOLD_MODE_RELATIVE         = 0x40;
const uint8_t _PEDOMETER3_CNTL4_WAKE_UP_DISABLE                 = 0x00;
const uint8_t _PEDOMETER3_CNTL4_WAKE_UP_ENABLE                  = 0x20;
const uint8_t _PEDOMETER3_CNTL4_BACK_TO_SLEEP_DISABLE           = 0x00;
const uint8_t _PEDOMETER3_CNTL4_BACK_TO_SLEEP_ENABLE            = 0x10;
const uint8_t _PEDOMETER3_CNTL4_HIGH_PASS_DISABLE               = 0x00;
const uint8_t _PEDOMETER3_CNTL4_HIGH_PASS_ENABLE                = 0x08;
const uint8_t _PEDOMETER3_CNTL4_OBTS_OUTPUT_DATA_RATE_0_781Hz   = 0x00; // Def
const uint8_t _PEDOMETER3_CNTL4_OBTS_OUTPUT_DATA_RATE_1_563Hz   = 0x01;
const uint8_t _PEDOMETER3_CNTL4_OBTS_OUTPUT_DATA_RATE_3_125Hz   = 0x02;
const uint8_t _PEDOMETER3_CNTL4_OBTS_OUTPUT_DATA_RATE_6_250Hz   = 0x03;
const uint8_t _PEDOMETER3_CNTL4_OBTS_OUTPUT_DATA_RATE_12_5Hz    = 0x04;
const uint8_t _PEDOMETER3_CNTL4_OBTS_OUTPUT_DATA_RATE_25Hz      = 0x05;
const uint8_t _PEDOMETER3_CNTL4_OBTS_OUTPUT_DATA_RATE_50Hz      = 0x06;
const uint8_t _PEDOMETER3_CNTL4_OBTS_OUTPUT_DATA_RATE_100Hz     = 0x07;

/* Control register 5 */
const uint8_t _PEDOMETER3_CNTL5_MANUAL_WAKE_UP_0   = 0x00;
const uint8_t _PEDOMETER3_CNTL5_MANUAL_WAKE_UP_1   = 0x02;
const uint8_t _PEDOMETER3_CNTL5_MANUAL_SLEEP_UP_0  = 0x00;
const uint8_t _PEDOMETER3_CNTL5_MANUAL_SLEEP_UP_1  = 0x01;

/* Output data control */
const uint8_t _PEDOMETER3_ODCNTL_IR_BYPASS_FILTERING_APPLIED  = 0x00;
const uint8_t _PEDOMETER3_ODCNTL_IR_BYPASS_FILTER_BYPASSED    = 0x80;
const uint8_t _PEDOMETER3_ODCNTL_LPRO_ODR_9                   = 0x00;
const uint8_t _PEDOMETER3_ODCNTL_LPRO_ODR_2                   = 0x40;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_12_5Hz  = 0x00;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_25Hz    = 0x01;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_50Hz    = 0x02;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_100Hz   = 0x03;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_200Hz   = 0x04;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_400Hz   = 0x05;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_800Hz   = 0x06;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_1600Hz  = 0x07;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_0_781Hz = 0x08;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_1_563Hz = 0x09;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_3_125Hz = 0x0A;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_6_25Hz  = 0x0B;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_3200Hz  = 0x0C;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_6400Hz  = 0x0D;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_12800Hz = 0x0E;
const uint8_t _PEDOMETER3_ODCNTL_OSA_OUTPUT_DATA_RATE_25600Hz = 0x0F;

/* Interrupt Control 1 */
const uint8_t _PEDOMETER3_INC1_PULSE_INTERRUPT_1_50uSec      = 0x00;
const uint8_t _PEDOMETER3_INC1_PULSE_INTERRUPT_1_OSA_PERIOD  = 0x40;
const uint8_t _PEDOMETER3_INC1_PULSE_INTERRUPT_1_OSA2_PERIOD = 0x80;
const uint8_t _PEDOMETER3_INC1_PULSE_INTERRUPT_1_OSA4_PERIOD = 0xC0;
const uint8_t _PEDOMETER3_INC1_PHYSICAL_INTERRUPT_DISABLE    = 0x00;
const uint8_t _PEDOMETER3_INC1_PHYSICAL_INTERRUPT_ENABLE     = 0x20;
const uint8_t _PEDOMETER3_INC1_INTERRUPT_ACTIVE_LEVEL_LOW    = 0x00;
const uint8_t _PEDOMETER3_INC1_INTERRUPT_ACTIVE_LEVEL_HIGH   = 0x10;
const uint8_t _PEDOMETER3_INC1_INTERRUPT_LATCHED             = 0x00;
const uint8_t _PEDOMETER3_INC1_INTERRUPT_PULSED              = 0x08;
const uint8_t _PEDOMETER3_INC1_SELF_TEST_POLARITY_NEGATIVE   = 0x00;
const uint8_t _PEDOMETER3_INC1_SELF_TEST_POLARITY_POSITIVE   = 0x02;
const uint8_t _PEDOMETER3_INC1_3_WIRE_SPI_INTERFACE_DISABLE  = 0x00;
const uint8_t _PEDOMETER3_INC1_3_WIRE_SPI_INTERFACE_ENABLED  = 0x01;

/* Interrupt Control 2 */
const uint8_t _PEDOMETER3_INC2_AOI_ACTIVE_STATE_IN_OR    = 0x00;
const uint8_t _PEDOMETER3_INC2_AOI_ACTIVE_STATE_IN_AND   = 0x40;
const uint8_t _PEDOMETER3_INC2_X_NEGATIVE_DISABLE        = 0x00;
const uint8_t _PEDOMETER3_INC2_X_NEGATIVE_ENABEL         = 0x20;
const uint8_t _PEDOMETER3_INC2_Y_NEGATIVE_DISABLE        = 0x00;
const uint8_t _PEDOMETER3_INC2_Y_NEGATIVE_ENABEL         = 0x08;
const uint8_t _PEDOMETER3_INC2_Z_NEGATIVE_DISABLE        = 0x00;
const uint8_t _PEDOMETER3_INC2_Z_NEGATIVE_ENABEL         = 0x02;
const uint8_t _PEDOMETER3_INC2_X_POSITIVE_DISABLE        = 0x00;
const uint8_t _PEDOMETER3_INC2_X_POSITIVE_ENABEL         = 0x10;
const uint8_t _PEDOMETER3_INC2_Y_POSITIVE_DISABLE        = 0x00;
const uint8_t _PEDOMETER3_INC2_Y_POSITIVE_ENABEL         = 0x04;
const uint8_t _PEDOMETER3_INC2_Z_POSITIVE_DISABLE        = 0x00;
const uint8_t _PEDOMETER3_INC2_Z_POSITIVE_ENABEL         = 0x01;

/* Interrupt Control 3 */
const uint8_t _PEDOMETER3_INC3_ALTERNATE_TAP_DISABLE     = 0x00;
const uint8_t _PEDOMETER3_INC3_ALTERNATE_TAP_ENABLE      = 0x40;
const uint8_t _PEDOMETER3_INC3_LEFT_STATE_DISABLE        = 0x00;
const uint8_t _PEDOMETER3_INC3_LEFT_STATE_ENABLE         = 0x20;
const uint8_t _PEDOMETER3_INC3_RIGHT_STATE_DISABLE       = 0x00;
const uint8_t _PEDOMETER3_INC3_RIGHT_STATE_ENABLE        = 0x10;
const uint8_t _PEDOMETER3_INC3_DOWN_STATE_DISABLE        = 0x00;
const uint8_t _PEDOMETER3_INC3_DOWN_STATE_ENABLE         = 0x08;
const uint8_t _PEDOMETER3_INC3_UP_STATE_DISABLE          = 0x00;
const uint8_t _PEDOMETER3_INC3_UP_STATE_ENABLE           = 0x04;
const uint8_t _PEDOMETER3_INC3_FACE_DOWN_STATE_DISABLE   = 0x00;
const uint8_t _PEDOMETER3_INC3_FACE_DOWN_STATE_ENABLE    = 0x02;
const uint8_t _PEDOMETER3_INC3_FACE_UP_STATE_DISABLE     = 0x00;
const uint8_t _PEDOMETER3_INC3_FACE_UP_STATE_ENABLE      = 0x01;

/* Interrupt Control 4 */
const uint8_t _PEDOMETER3_INC4_FREE_FALL_INTERRUPT_1_DISABLE     = 0x00;
const uint8_t _PEDOMETER3_INC4_FREE_FALL_INTERRUPT_1_ENABLE      = 0x80;
const uint8_t _PEDOMETER3_INC4_BUFFER_FULL_INTERRUPT_1_DISABLE   = 0x00;
const uint8_t _PEDOMETER3_INC4_BUFFER_FULL_INTERRUPT_1_ENABLE    = 0x40;
const uint8_t _PEDOMETER3_INC4_WATERMARK_INTERRUPT_1_DISABLE     = 0x00;
const uint8_t _PEDOMETER3_INC4_WATERMARK_INTERRUPT_1_ENABLE      = 0x20;
const uint8_t _PEDOMETER3_INC4_DATA_READY_INTERRUPT_1_DISABLE    = 0x00;
const uint8_t _PEDOMETER3_INC4_DATA_READY_INTERRUPT_1_ENABLE     = 0x10;
const uint8_t _PEDOMETER3_INC4_BACK_TO_SLEEP_INTERRUPT_1_DISABLE = 0x00;
const uint8_t _PEDOMETER3_INC4_BACK_TO_SLEEP_INTERRUPT_1_ENABLE  = 0x08;
const uint8_t _PEDOMETER3_INC4_TAP_INTERRUPT_1_DISABLE           = 0x00;
const uint8_t _PEDOMETER3_INC4_TAP_INTERRUPT_1_ENABLE            = 0x04;
const uint8_t _PEDOMETER3_INC4_WAKE_UP_INTERRUPT_1_DISABLE       = 0x00;
const uint8_t _PEDOMETER3_INC4_WAKE_UP_INTERRUPT_1_ENABLE        = 0x02;
const uint8_t _PEDOMETER3_INC4_TILT_POSITION_INTERRUPT_1_DISABLE = 0x00;
const uint8_t _PEDOMETER3_INC4_TILT_POSITION_INTERRUPT_1_ENABLE  = 0x01;

/* Interrupt Control 5 */
const uint8_t _PEDOMETER3_INC5_PULSE_INTERRUPT_2_50uSec      = 0x00;
const uint8_t _PEDOMETER3_INC5_PULSE_INTERRUPT_2_OSA_PERIOD  = 0x40;
const uint8_t _PEDOMETER3_INC5_PULSE_INTERRUPT_2_OSA2_PERIOD = 0x80;
const uint8_t _PEDOMETER3_INC5_PULSE_INTERRUPT_2_OSA4_PERIOD = 0xC0;
const uint8_t _PEDOMETER3_INC5_PHYSICAL_INTERRUPT_DISABLE    = 0x00;
const uint8_t _PEDOMETER3_INC5_PHYSICAL_INTERRUPT_ENABLE     = 0x20;
const uint8_t _PEDOMETER3_INC5_INTERRUPT_ACTIVE_LEVEL_LOW    = 0x00;
const uint8_t _PEDOMETER3_INC5_INTERRUPT_ACTIVE_LEVEL_HIGH   = 0x10;
const uint8_t _PEDOMETER3_INC5_INTERRUPT_LATCHED             = 0x00;
const uint8_t _PEDOMETER3_INC5_INTERRUPT_PULSED              = 0x08;
const uint8_t _PEDOMETER3_INC5_LATCHED_INTERRUPT_2_DISABLE   = 0x00;
const uint8_t _PEDOMETER3_INC5_LATCHED_INTERRUPT_2_ENABLE    = 0x02;
const uint8_t _PEDOMETER3_INC5_LATCHED_INTERRUPT_1_DISABLE   = 0x00;
const uint8_t _PEDOMETER3_INC5_LATCHED_INTERRUPT_1_ENABLE    = 0x01;

/* Interrupt Control 6 */
const uint8_t _PEDOMETER3_INC6_FREE_FALL_INTERRUPT_2_DISABLE     = 0x00;
const uint8_t _PEDOMETER3_INC6_FREE_FALL_INTERRUPT_2_ENABLE      = 0x80;
const uint8_t _PEDOMETER3_INC6_BUFFER_FULL_INTERRUPT_2_DISABLE   = 0x00;
const uint8_t _PEDOMETER3_INC6_BUFFER_FULL_INTERRUPT_2_ENABLE    = 0x40;
const uint8_t _PEDOMETER3_INC6_WATERMARK_INTERRUPT_2_DISABLE     = 0x00;
const uint8_t _PEDOMETER3_INC6_WATERMARK_INTERRUPT_2_ENABLE      = 0x20;
const uint8_t _PEDOMETER3_INC6_DATA_READY_INTERRUPT_2_DISABLE    = 0x00;
const uint8_t _PEDOMETER3_INC6_DATA_READY_INTERRUPT_2_ENABLE     = 0x10;
const uint8_t _PEDOMETER3_INC6_BACK_TO_SLEEP_INTERRUPT_2_DISABLE = 0x00;
const uint8_t _PEDOMETER3_INC6_BACK_TO_SLEEP_INTERRUPT_2_ENABLE  = 0x08;
const uint8_t _PEDOMETER3_INC6_TAP_INTERRUPT_2_DISABLE           = 0x00;
const uint8_t _PEDOMETER3_INC6_TAP_INTERRUPT_2_ENABLE            = 0x04;
const uint8_t _PEDOMETER3_INC6_WAKE_UP_INTERRUPT_2_DISABLE       = 0x00;
const uint8_t _PEDOMETER3_INC6_WAKE_UP_INTERRUPT_2_ENABLE        = 0x02;
const uint8_t _PEDOMETER3_INC6_TILT_POSITION_INTERRUPT_2_DISABLE = 0x00;
const uint8_t _PEDOMETER3_INC6_TILT_POSITION_INTERRUPT_2_ENABLE  = 0x01;

/* Interrupt Control 7 */
const uint8_t _PEDOMETER3_INC7_STEP_OVERFLOW_INTERRUPT_2_DISABLE   = 0x00;
const uint8_t _PEDOMETER3_INC7_STEP_OVERFLOW_INTERRUPT_2_ENABLE    = 0x40;
const uint8_t _PEDOMETER3_INC7_STEP_WATERMARK_INTERRUPT_2_DISABLE  = 0x00;
const uint8_t _PEDOMETER3_INC7_STEP_WATERMARK_INTERRUPT_2_ENABLE   = 0x20;
const uint8_t _PEDOMETER3_INC7_STEP_INCREMENT_INTERRUPT_2_DISABLE  = 0x00;
const uint8_t _PEDOMETER3_INC7_STEP_INCREMENT_INTERRUPT_2_ENABLE   = 0x10;
const uint8_t _PEDOMETER3_INC7_STEP_OVERFLOW_INTERRUPT_1_DISABLE   = 0x00;
const uint8_t _PEDOMETER3_INC7_STEP_OVERFLOW_INTERRUPT_1_ENABLE    = 0x04;
const uint8_t _PEDOMETER3_INC7_STEP_WATERMARK_INTERRUPT_1_DISABLE  = 0x00;
const uint8_t _PEDOMETER3_INC7_STEP_WATERMARK_INTERRUPT_1_ENABLE   = 0x02;
const uint8_t _PEDOMETER3_INC7_STEP_INCREMENT_INTERRUPT_1_DISABLE  = 0x00;
const uint8_t _PEDOMETER3_INC7_STEP_INCREMENT_INTERRUPT_1_ENABLE   = 0x01;

/* Tap Report Control */
const uint8_t _PEDOMETER3_TDTRC_DOUBLE_TAP_INTERRUPT_DISABLE   = 0x00;
const uint8_t _PEDOMETER3_TDTRC_DOUBLE_TAP_INTERRUPT_ENABLE    = 0x02;
const uint8_t _PEDOMETER3_TDTRC_SINGLE_TAP_INTERRUPT_DISABLE   = 0x00;
const uint8_t _PEDOMETER3_TDTRC_SINGLE_TAP_INTERRUPT_ENABLE    = 0x01;

/* Free Fall Control */
const uint8_t _PEDOMETER3_FFCNTL_FREE_FALL_DISABLE                  = 0x00;
const uint8_t _PEDOMETER3_FFCNTL_FREE_FALL_ENABLE                   = 0x80;
const uint8_t _PEDOMETER3_FFCNTL_FREE_FALL_INTERRUPT_LATCH_DISABLE  = 0x00;
const uint8_t _PEDOMETER3_FFCNTL_FREE_FALL_INTERRUPT_UNLATCH_ENABLE = 0x40;
const uint8_t _PEDOMETER3_FFCNTL_DEBOUNCE_METHODOLOGY_DISABLE       = 0x00;
const uint8_t _PEDOMETER3_FFCNTL_DEBOUNCE_METHODOLOGY_ENABLE        = 0x08;
const uint8_t _PEDOMETER3_FFCNTL_OFFI_OUTPUT_DATA_RATE_12_5Hz       = 0x00;
const uint8_t _PEDOMETER3_FFCNTL_OFFI_OUTPUT_DATA_RATE_25Hz         = 0x01;
const uint8_t _PEDOMETER3_FFCNTL_OFFI_OUTPUT_DATA_RATE_50Hz         = 0x02;
const uint8_t _PEDOMETER3_FFCNTL_OFFI_OUTPUT_DATA_RATE_100Hz        = 0x03;
const uint8_t _PEDOMETER3_FFCNTL_OFFI_OUTPUT_DATA_RATE_200Hz        = 0x04;
const uint8_t _PEDOMETER3_FFCNTL_OFFI_OUTPUT_DATA_RATE_400Hz        = 0x05;
const uint8_t _PEDOMETER3_FFCNTL_OFFI_OUTPUT_DATA_RATE_800Hz        = 0x06;
const uint8_t _PEDOMETER3_FFCNTL_OFFI_OUTPUT_DATA_RATE_1600Hz       = 0x07;

/* Low Power Control */
const uint8_t _PEDOMETER3_LP_CNTL_NO_AVERAGING         = 0x00;
const uint8_t _PEDOMETER3_LP_CNTL_2_SAMPLES_AVERAGED   = 0x10;
const uint8_t _PEDOMETER3_LP_CNTL_4_SAMPLES_AVERAGED   = 0x20;
const uint8_t _PEDOMETER3_LP_CNTL_8_SAMPLES_AVERAGED   = 0x30;
const uint8_t _PEDOMETER3_LP_CNTL_16_SAMPLES_AVERAGED  = 0x40;
const uint8_t _PEDOMETER3_LP_CNTL_32_SAMPLES_AVERAGED  = 0x50;
const uint8_t _PEDOMETER3_LP_CNTL_64_SAMPLES_AVERAGED  = 0x60;
const uint8_t _PEDOMETER3_LP_CNTL_128_SAMPLES_AVERAGED = 0x70;

/* Pedometer Control register 1 */
const uint8_t _PEDOMETER3_PED_CNTL1_STEP_TH_NO_STEPS   = 0x00;
const uint8_t _PEDOMETER3_PED_CNTL1_STEP_TH_2_STEPS    = 0x01;
const uint8_t _PEDOMETER3_PED_CNTL1_STEP_TH_4_STEPS    = 0x02;
const uint8_t _PEDOMETER3_PED_CNTL1_STEP_TH_6_STEPS    = 0x03;
const uint8_t _PEDOMETER3_PED_CNTL1_STEP_TH_8_STEPS    = 0x04;
const uint8_t _PEDOMETER3_PED_CNTL1_STEP_TH_10_STEPS   = 0x05;
const uint8_t _PEDOMETER3_PED_CNTL1_STEP_TH_12_STEPS   = 0x06;
const uint8_t _PEDOMETER3_PED_CNTL1_STEP_TH_14_STEPS   = 0x07;

/* Pedometer Control register 2 */
const uint8_t _PEDOMETER3_PED_CNTL2_HIGH_PASS_FILTER_1   = 0x00;
const uint8_t _PEDOMETER3_PED_CNTL2_HIGH_PASS_FILTER_2   = 0x10;
const uint8_t _PEDOMETER3_PED_CNTL2_HIGH_PASS_FILTER_4   = 0x20;
const uint8_t _PEDOMETER3_PED_CNTL2_HIGH_PASS_FILTER_8   = 0x30;
const uint8_t _PEDOMETER3_PED_CNTL2_HIGH_PASS_FILTER_16  = 0x40;
const uint8_t _PEDOMETER3_PED_CNTL2_HIGH_PASS_FILTER_32  = 0x50;
const uint8_t _PEDOMETER3_PED_CNTL2_HIGH_PASS_FILTER_64  = 0x60;
const uint8_t _PEDOMETER3_PED_CNTL2_HIGH_PASS_FILTER_128 = 0x70;
const uint8_t _PEDOMETER3_PED_CNTL2_ODR_SELECT_100Hz     = 0x0C;
const uint8_t _PEDOMETER3_PED_CNTL2_ODR_SELECT_50Hz      = 0x06;

/* Device slave address */
const uint8_t _PEDOMETER3_SLAVE_ADDRESS_0  = 0x1E;
const uint8_t _PEDOMETER3_SLAVE_ADDRESS_1  = 0x1F;

/* Current Tilt Position *** Previous Tilt Positon */
const uint8_t _PEDOMETER3_TILT_POSITION_LEFT      = 1;
const uint8_t _PEDOMETER3_TILT_POSITION_RIGHT     = 2;
const uint8_t _PEDOMETER3_TILT_POSITION_DOWN      = 3;
const uint8_t _PEDOMETER3_TILT_POSITION_UP        = 4;
const uint8_t _PEDOMETER3_TILT_POSITION_FACE_DOWN = 5;
const uint8_t _PEDOMETER3_TILT_POSITION_FACE_UP   = 6;

/* Tap detection */
const uint8_t _PEDOMETER3_TAP_X_NEGATIVE   = 0x10;
const uint8_t _PEDOMETER3_TAP_X_POSITIVE   = 0x11;
const uint8_t _PEDOMETER3_TAP_Y_NEGATIVE   = 0x20;
const uint8_t _PEDOMETER3_TAP_Y_POSITIVE   = 0x21;
const uint8_t _PEDOMETER3_TAP_Z_NEGATIVE   = 0x30;
const uint8_t _PEDOMETER3_TAP_Z_POSITIVE   = 0x31;

//#include <msp430.h>
// * --/COPYRIGHT--
//******************************************************************************
//   MSP430G2xx3 Demo - USCI_A0, SPI 3-Wire Slave Data Echo
//
//   Description: SPI slave talks to SPI master using 3-wire mode. Data received
//   from master is echoed back.  USCI RX ISR is used to handle communication,
//   CPU normally in LPM4.  Prior to initial data exchange, master pulses
//   slaves RST for complete reset.
//   ACLK = n/a, MCLK = SMCLK = DCO ~1.2MHz
//
//   Use with SPI Master Incremented Data code example.  If the slave is in
//   debug mode, the reset signal from the master will conflict with slave's
//   JTAG; to work around, use IAR's "Release JTAG on Go" on slave device.  If
//   breakpoints are set in slave RX ISR, master must stopped also to avoid
//   overrunning slave RXBUF.
//
//                MSP430G2xx3
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          | |             XOUT|-
// Master---+-|RST              |
//            |             P1.2|<- Data Out (UCA0SOMI)
//            |                 |
//            |             P1.1|-> Data In (UCA0SIMO)
//            |                 |
//            |             P1.4|<- Serial Clock In (UCA0CLK)
//
//   D. Dang
//   Texas Instruments Inc.
//   February 2011
//   Built with CCS Version 4.2.0 and IAR Embedded Workbench Version: 5.10
//******************************************************************************
#include <msp430.h>
#include <stdint.h>






/*

def init(self):
    """ Initialization for the KX126-1063.
    Default setting is +/- 2g range.
    """
    # Software reset
    val = i2c.readU8(KX126_CNTL2)
    i2c.write8(KX126_CNTL2, (val | KX126_CNTL2_SRST))
    # Delay 2 milliseconds
    time.sleep(RESET_DELAY)
    # Enter standby mode
    i2c.write8(KX126_CNTL1, 0x00)
    # Disable interrupts
    i2c.write8(KX126_INC1, 0x00)
    i2c.write8(KX126_INC5, 0x00)
    # Initialize the pedometer engine settings
    self.init_ped()
    # Output data rate
    val = i2c.readU8(KX126_ODCNTL)
    i2c.write8(KX126_ODCNTL, (val | KX126_ODCNTL_OSA_100HZ))
    # High resolution
    val = i2c.readU8(KX126_CNTL1) # should be 0x00
    i2c.write8(KX126_CNTL1, (val | KX126_CNTL1_RES))
    # Enable pedometer engine
    val = i2c.readU8(KX126_CNTL1) # should be 0x40 (64)
    i2c.write8(KX126_CNTL1, (val | KX126_CNTL1_PDE))
    # Exit standby mode
    val = i2c.readU8(KX126_CNTL1) # should be 0x42 (66)
    i2c.write8(KX126_CNTL1, (val | KX126_CNTL1_PC1))
    val = i2c.readU8(KX126_CNTL1) # should be 0xC2 (194)
    time.sleep(2)
# End def

def init_ped(self):
    """ Initialization for the pedometer engine settings. See the app note
    on Getting Started with Pedometer.
    """
    # Number of internal acceleration samples used by ped engine
    val = i2c.readU8(KX126_LPCNTL)
    i2c.write8(KX126_LPCNTL, (val | KX126_LPCNTL_4))
    # Number of steps before counting
    val = i2c.readU8(KX126_PED_CNTL1)
    i2c.write8(KX126_PED_CNTL1, (val | KX126_PED_CNTL1_STPTH_2))
    # Scaling factor for HPF and output data rate for the pedometer engine
    val = i2c.readU8(KX126_PED_CNTL2)
    i2c.write8(KX126_PED_CNTL2, (val | KX126_PED_CNTL2_HPS_4 | KX126_PED_CNTL2_ODR_100))
    # Scaling factor for internal HPF
    i2c.write8(KX126_PED_CNTL3, 0x17)
    # Maximum impact from floor
    i2c.write8(KX126_PED_CNTL4, 0x1F)
    # Minimum impact from floor (adjust this for sensitivity)
    i2c.write8(KX126_PED_CNTL5, 0x0A)
    # Maximum time interval for the peak
    i2c.write8(KX126_PED_CNTL6, 0x13)
    # Minimum time interval for the peak
    i2c.write8(KX126_PED_CNTL7, 0x0B)
    # Time window for noise and delay time
    i2c.write8(KX126_PED_CNTL8, 0x08)
    # Time interval to prevent overflowing
    i2c.write8(KX126_PED_CNTL9, 0x19)
    # Minimum time interval for a single stride
    i2c.write8(KX126_PED_CNTL10, 0x1C)
# End def
*/



//UCA0CTL0 |= UCCKPH + UCSYNC + UCMST + UCMSB;  // Clock phase sync mode, Synchronous  (SPI), Master Mode on, MSB first direction for the RX/TX shifter register
    //UCA0CTL1 |= UCSSEL_2;                         // Select SMCLK as source
    //UCA0BR1 |= 0;
    //UCA0BR0 |= 0x02;                              // Baud rate settings, clock divide by 2
    //UCA0CTL1 &= ~UCSWRST;
    //P1OUT &= (~BIT5); // Select Device
    //while (!(IFG2 & UCA0TXIFG)); // USCI_A0 TX buffer ready?
    //UCA0TXBUF = 0xAA; // Send 0xAA over SPI to Slave
    //while (!(IFG2 & UCA0RXIFG)); // USCI_A0 RX Received?
    //received_ch = UCA0RXBUF; // Store received data
    //P1OUT |= (BIT5); // Unselect Device    //P1SEL = BIT1 + BIT2 + BIT4;
    //P1SEL2 = BIT1 + BIT2 + BIT4;
    //UCA0CTL1 = UCSWRST;                       // **Put state machine in reset**
    //UCA0CTL0 |= UCCKPL + UCMSB + UCSYNC;      // 3-pin, 8-bit SPI master
    //UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
    //IE2 |= UCA0RXIE;                          // Enable USCI0 RX interrupt










/*


def init(self):
    """ Initialization for the KX126-1063.
    Default setting is +/- 2g range.
    """
    # Software reset
    val = i2c.readU8(KX126_CNTL2)
    i2c.write8(KX126_CNTL2, (val | KX126_CNTL2_SRST))
    # Delay 2 milliseconds
    time.sleep(RESET_DELAY)
    # Enter standby mode
    i2c.write8(KX126_CNTL1, 0x00)
    # Disable interrupts
    i2c.write8(KX126_INC1, 0x00)
    i2c.write8(KX126_INC5, 0x00)
    # Initialize the pedometer engine settings
    self.init_ped()
    # Output data rate
    val = i2c.readU8(KX126_ODCNTL)
    i2c.write8(KX126_ODCNTL, (val | KX126_ODCNTL_OSA_100HZ))
    # High resolution
    val = i2c.readU8(KX126_CNTL1) # should be 0x00
    i2c.write8(KX126_CNTL1, (val | KX126_CNTL1_RES))
    # Enable pedometer engine
    val = i2c.readU8(KX126_CNTL1) # should be 0x40 (64)
    i2c.write8(KX126_CNTL1, (val | KX126_CNTL1_PDE))
    # Exit standby mode
    val = i2c.readU8(KX126_CNTL1) # should be 0x42 (66)
    i2c.write8(KX126_CNTL1, (val | KX126_CNTL1_PC1))
    val = i2c.readU8(KX126_CNTL1) # should be 0xC2 (194)
    time.sleep(2)
# End def



void write2sen( uint8_t *message){
    unsigned int byte1;
    //P1OUT &= (~BIT5); // Gnd - off
    message[0] |= 0x80;
    for (byte1=0;byte1<2; byte1++){//send 32 bit frame in 8 bit chunks
        if (byte1 == 0){P1OUT &= (~BIT5);}// VDD - on}

        UCA0TXBUF=message[byte1];
        if (byte1 == 2){P1OUT |= (BIT5);}// VDD - on}
        while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
    }
     // Gnd - off
    //if (wait_focompletion)r_
    P1OUT |= (BIT5);// VDD - on

    __delay_cycles(10000);

    //while (!(IFG2 & UCA0RXIFG));  // USCI_A0 RX buffer ready? (indicates transfer complete)
    //P1OUT &= (~BIT5);
}

void read2sen(uint8_t address){
    volatile char received_ch = 0;

    //address |= BIT7;
    P1OUT &= (~BIT5); // Gnd - off

    while (!(IFG2 & UCA0TXIFG)); // USCI_A0 TX buffer ready?
    UCA0TXBUF = address; // Send 0xAA over SPI to Slave

    while (!(IFG2 & UCA0RXIFG)); // USCI_A0 RX Received?
    received_ch = UCA0RXBUF; // Store received data
    P1OUT |= (BIT5);// VDD - on


}
*/





void spi_setup(void)
{   WDTCTL = WDTPW + WDTHOLD; // Stop WDT
    UCA0CTL1 |= UCSWRST;                          // Enable SPI software rezet
    UCA0CTL1 |= UCSSEL_2; // SMCLK clock
    UCA0CTL0 |= UCSYNC; // spi
    UCA0CTL0 |= UCMST; //master
    UCA0CTL0 |= UCMSB; //MSB
    UCA0CTL0 |= UCMODE_1; //master

    UCA0BR0  |= 0x02; // /2 --> 100 khz


   //UCA0CTL0 |= UCCKPH + UCMSB + UCMODE_1; // 4-pin, 8-bit SPI master
   //UCA0CTL0 |= UCCKPH + UCMSB + UCMST + UCSYNC; // 3-pin, 8-bit SPI master
    //UCA0BR1 = 0; //
    //UCA0MCTL = 0; // No modulation
    UCA0CTL1 &= ~UCSWRST; // **Initialize USCI state machine**


    P1SEL  |= BIT1;                               // Just setup for the pins (1.1 is the SOMI)
    P1SEL2 |= BIT1;

    P1SEL  |= BIT2;                               // Just setup for the pins (1.2 is the SIMO data line)
    P1SEL2 |= BIT2;

    P1SEL  |= BIT4;                               // Just setup for the pins (1.4 is the USCI clock)
    P1SEL2 |= BIT4;


    P1DIR |= BIT5;
    P1OUT |= (BIT5);// VDD - on
}


void write2sen( uint8_t *message){
    unsigned int byte1;
    //P1OUT &= (~BIT5); // Gnd - off
    message[0] |= 0x80;
    for (byte1=0;byte1<2; byte1++){//send 32 bit frame in 8 bit chunks
        if (byte1 == 0){P1OUT &= (~BIT5);}// VDD - on}

        UCA0TXBUF=message[byte1];
        if (byte1 == 2){P1OUT |= (BIT5);}// VDD - on}
        while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
    }
     // Gnd - off
    //if (wait_focompletion)r_
    P1OUT |= (BIT5);// VDD - on

    __delay_cycles(10000);
    //while (!(IFG2 & UCA0RXIFG));  // USCI_A0 RX buffer ready? (indicates transfer complete)
    //P1OUT &= (~BIT5);
}




//uint8_t
void write2sen2( uint8_t *message){
    volatile char received_ch = 0;

    unsigned int byte1;

    for (byte1=0;byte1<4; byte1++){//send 32 bit frame in 8 bit chunks
        if (byte1 == 0){P1OUT &= (~BIT5);
        UCA0TXBUF=message[byte1];
        }
        else{        UCA0TXBUF=0x00;
        received_ch = UCA0RXBUF;
}
        //UCA0TXBUF=message[byte1];
        if (byte1 == 4){P1OUT |= (BIT5);}// VDD - on}
        while (!(IFG2 & UCA0RXIFG));  // USCI_A0 TX buffer ready?
    }
     // Gnd - off
    //if (wait_focompletion)r_
    P1OUT |= (BIT5);// VDD - on

    __delay_cycles(10000);
    //while (!(IFG2 & UCA0RXIFG));  // USCI_A0 RX buffer ready? (indicates transfer complete)
    //P1OUT &= (~BIT5);
    //return received_ch;
}




uint8_t write2sen22( uint8_t *message){
    volatile char received_ch = 0;

    unsigned int byte1;

    for (byte1=0;byte1<4; byte1++){//send 32 bit frame in 8 bit chunks
        if (byte1 == 0){P1OUT &= (~BIT5);
        UCA0TXBUF=message[byte1];
        }
        else{        UCA0TXBUF=0x00;
        received_ch = UCA0RXBUF;
        }
        //UCA0TXBUF=message[byte1];
        if (byte1 == 4){P1OUT |= (BIT5);}// VDD - on}
        while (!(IFG2 & UCA0RXIFG));  // USCI_A0 TX buffer ready?
    }
     // Gnd - off
    //if (wait_focompletion)r_
    P1OUT |= (BIT5);// VDD - on

    __delay_cycles(10000);
    //while (!(IFG2 & UCA0RXIFG));  // USCI_A0 RX buffer ready? (indicates transfer complete)
    //P1OUT &= (~BIT5);
    return received_ch;
}








uint8_t read2sen(uint8_t address){
    volatile char received_ch = 0;
    unsigned int byte1;
    for (byte1=0;byte1<4; byte1++){//send 32 bit frame in 8 bit chunks
        if (byte1 == 0){P1OUT &= (~BIT5);
        UCA0TXBUF = address;
        }// VDD - on}
        else{
        UCA0TXBUF= 0x00;
        received_ch = UCA0RXBUF;
        }
        if (byte1 == 4){P1OUT |= (BIT5);}// VDD - on}
        while (!(IFG2 & UCA0RXIFG));  // USCI_A0 TX buffer ready?
    }

    P1OUT |= (BIT5);// VDD - on
    __delay_cycles(1000);
return received_ch;
}

    /*
    //address |= BIT7;
    P1OUT &= (~BIT5); // Gnd - off

    while (!(IFG2 & UCA0TXIFG)); // USCI_A0 TX buffer ready?
    UCA0TXBUF = address; // Send 0xAA over SPI to Slave

    while (!(IFG2 & UCA0RXIFG)); // USCI_A0 RX Received?
    received_ch = UCA0RXBUF; // Store received data
    P1OUT |= (BIT5);// VDD - on
*/

//}



uint8_t CNTL2[] =       {0x1B,0x80};//,0x00,0x00};
uint8_t INC7[] =        {0x27,0x00};//,0x00,0x00};
uint8_t INC1[] =        {0x20,0x00};//,0x00,0x00};
uint8_t INC5[] =        {0x24,0x00};//,0x00,0x00};
uint8_t LPCNTL =        {0x37,0x20};

uint8_t PED_CENTL1[] =    {0x43,0x10};
uint8_t PED_CENTL2[] =    {0x44,0x2C};
uint8_t PED_CENTL3[] =    {0x45,0x17};
uint8_t PED_CENTL4[] =    {0x46,0x1F};
uint8_t PED_CENTL5[] =    {0x47,0x0A};
uint8_t PED_CENTL6[] =    {0x48,0x13};
uint8_t PED_CENTL7[] =    {0x49,0x0B};
uint8_t PED_CENTL8[] =    {0x4A,0x08};
uint8_t PED_CENTL9[] =    {0x4B,0x19};
uint8_t PED_CENTL10[]=    {0x4C,0x1C};

uint8_t ODCNTL[] =        {0x4C,0x1C};
uint8_t CNTL1[] =         {0x4C,0x1C};



//uint8_t CNTL1[] =       {0x1A,0x00};//,0x00,0x00};
uint8_t PED_STPWM_L[] = {0x41,0x10};//,0x00,0x00};
uint8_t PED_STPWM_H[] = {0x42,0x27};//,0x00,0x00};
uint8_t PED_CNTL2[] =   {0x44,0x2C};//,0x00,0x00};
uint8_t LP_CNTL[] =     {0x37,0x7B};//,0x00,0x00};

uint8_t hello;



volatile char received_ch = 0;





void delay_setup(){
      WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
      P1DIR |= 0x01;                            // P1.0 output
      CCTL0 = CCIE;                             // CCR0 interrupt enabled
      CCR0 = 31250;                             // first time when interupts turns off
      TACTL = TASSEL_2 + MC_2 + ID_3;           // SMCLK, contmode

}


void delay(unsigned int time){

    unsigned int timer;
    for (timer=0;timer<time; timer++){
        __bis_SR_register(LPM0_bits + GIE);
        CCR0 += 100;
    }
}


int main(void)
{spi_setup();
 delay_setup();




write2sen(CNTL1);
__delay_cycles(10000);

write2sen(CNTL1);
write2sen(PED_STPWM_L);
write2sen(PED_STPWM_H);
write2sen(PED_CNTL2);
write2sen(LP_CNTL);
write2sen(INC7);
write2sen(INC1);
write2sen(INC5);

hello =     write2sen22(PED_STPWM_L);



__delay_cycles(10000);
while(1)
{
    //P1OUT &= (~BIT5); // Gnd - off
    //P1OUT |= (BIT5);// VDD - on
    //write2sen(spi_array);
    //P1OUT |= (BIT5);// VDD - on
    //P1OUT &= (~BIT5); // Gnd - off
    __delay_cycles(100);


    write2sen2(CNTL1);
    write2sen2(PED_STPWM_L);
    write2sen2(PED_STPWM_H);
    write2sen2(PED_CNTL2);
    write2sen2(LP_CNTL);
    write2sen2(INC7);
    write2sen2(INC1);
    write2sen2(INC5);




    //hello = write2sen2(CNTL2);
    /*

    write2sen2(spi_array);
    write2sen2(spi_array);
    write2sen2(spi_array);
    write2sen2(spi_array);
    write2sen2(spi_array);
    write2sen2(spi_array);
    write2sen2(spi_array);
    write2sen2(spi_array);
    write2sen2(spi_array);
    write2sen2(spi_array);
*/

    /*
    write2sen(CNTL1);
    write2sen(PED_STPWM_L);
    write2sen(PED_STPWM_H);
    write2sen(PED_CNTL2);
    write2sen(LP_CNTL);
    write2sen(INC7);
    write2sen(INC1);
    write2sen(INC5);

    read2sen(0x20);

    read2sen(0x20);
    read2sen(0x20);
    read2sen(0x20);
    read2sen(0x20);
    read2sen(0x20);
    read2sen(0x20);

    //write2sen2(CNTL1);
    //write2sen2(PED_STPWM_L);
    //write2sen2(PED_STPWM_H);
    //write2sen2(PED_CNTL2);
    //write2sen2(LP_CNTL);
    //write2sen2(INC7);
    write2sen2(INC1);



    write2sen2(INC5);
    write2sen2(INC5);
    write2sen2(INC5);
    write2sen2(INC5);
    write2sen2(INC5);
    write2sen2(INC5);
    write2sen2(INC5);
// */

    //write2sen2(INC5);

///for (i = 0; i <= sizeof(spi_array); i++) { // Send Color Frame
   //       while(!(IFG2 & UCA0TXIFG)); // Buffer ready?
     //         UCA0TXBUF = spi_array[i];
       // }

        //__bis_SR_register(LPM3_bits + GIE);       // Enter LPM3 w/interrupt
/*
P1OUT &= (~BIT5); // Gnd - off

while (!(IFG2 & UCA0TXIFG)); // USCI_A0 TX buffer ready?
UCA0TXBUF = 0x1B; // Send 0xAA over SPI to Slave

while (!(IFG2 & UCA0RXIFG)); // USCI_A0 RX Received?
received_ch = UCA0RXBUF; // Store received data
P1OUT |= (BIT5);// VDD - on
*/
}


}











// Timer A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif
{
  __bic_SR_register_on_exit(LPM0_bits);
}






















/*
volatile char received_ch = 0;
int main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop WDT

P1OUT |= BIT5;
P1DIR |= BIT5;
P1SEL = BIT1 | BIT2 | BIT4;
P1SEL2 = BIT1 | BIT2 | BIT4;

UCA0CTL1 = UCSWRST;
UCA0CTL0 |= UCCKPH + UCMSB + UCMST + UCSYNC; // 3-pin, 8-bit SPI master
UCA0CTL1 |= UCSSEL_2; // SMCLK
UCA0BR0 |= 0x02; // /2
UCA0BR1 = 0; //
UCA0MCTL = 0; // No modulation
UCA0CTL1 &= ~UCSWRST; // **Initialize USCI state machine**
__enable_interrupt();
//P1OUT &= (~BIT5); // Select Device


while (!(IFG2 & UCA0TXIFG)); // USCI_A0 TX buffer ready?
__bis_SR_register(CPUOFF + GIE); // Low Power Mode 0 with interrupts enabled
UCA0TXBUF = 0xAA; // Send 0xAA over SPI to Slave
while (!(IFG2 & UCA0RXIFG)); // USCI_A0 RX Received?
__bis_SR_register(CPUOFF + GIE); // Low Power Mode 0 with interrupts enabled
received_ch = UCA0RXBUF; // Store received data

//P1OUT |= (BIT5); // Unselect Device





WDTCTL = WDTPW + WDTHOLD; // Stop WDT
BCSCTL1 = CALBC1_1MHZ; // Set range DCOCTL = CALDCO_1MHZ;
BCSCTL2 &= ~(DIVS_3); // SMCLK = DCO = 1MHz
P1SEL |= BIT3; // ADC input pin P1.3
ConfigureAdc(); // ADC set-up function call

// Enable interrupts.

//while(1)
{
//__delay_cycles(1000); // Wait for ADC Ref to settle
//ADC10CTL0 |= ENC + ADC10SC; // Sampling and conversion start
//__bis_SR_register(CPUOFF + GIE); // Low Power Mode 0 with interrupts enabled
//ADC_value = ADC10MEM; // Assigns the value held in ADC10MEM to the integer called ADC_value // change the variable name // take another code // try another analog input

//}

}
}

// ADC10 interrupt service routine

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR (void)
{
__bic_SR_register_on_exit(CPUOFF); // Return to active mode }
}












*/



/*
volatile unsigned int hello;
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  while (!(P1IN & BIT4));                   // If clock sig from mstr stays low,
                                            // it is not yet in SPI mode

  P1SEL = BIT1 + BIT2 + BIT4;
  P1SEL2 = BIT1 + BIT2 + BIT4;
  UCA0CTL1 = UCSWRST;                       // **Put state machine in reset**
  UCA0CTL0 |= UCCKPL + UCMSB + UCSYNC;      // 3-pin, 8-bit SPI master
  UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
  IE2 |= UCA0RXIE;                          // Enable USCI0 RX interrupt

  __bis_SR_register(LPM4_bits + GIE);       // Enter LPM4, enable interrupts
}

// Echo character
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(USCIAB0RX_VECTOR))) USCI0RX_ISR (void)
#else
#error Compiler not supported!
#endif
{ while (!(IFG2 & UCA0TXIFG));              // USCI_A0 TX buffer ready?
   //UCA0RXBUF
  //UCA0TXBUF =UCA0RXBUF;
    hello = UCA0RXBUF;
//printf("UCA0RXBUF\n");

}

//UCA0TXBUF = leds[i];





void SPI_setup(void) {
    UCA0CTL1 |= UCSWRST;                          // Enable SPI
    P1SEL  |= BIT1;                               // Just setup for the pins (1.1 is the SOMI)
    P1SEL2 |= BIT1;

    P1SEL  |= BIT2;                               // Just setup for the pins (1.2 is the SIMO data line)
    P1SEL2 |= BIT2;

    P1SEL  |= BIT4;                               // Just setup for the pins (1.4 is the USCI clock)
    P1SEL2 |= BIT4;



    UCA0CTL0 |= UCCKPH + UCSYNC + UCMST + UCMSB;  // Clock phase sync mode, Synchronous  (SPI), Master Mode on, MSB first direction for the RX/TX shifter register
    UCA0CTL1 |= UCSSEL_2;                         // Select SMCLK as source
    UCA0BR1 |= 0;
    UCA0BR0 |= 0x02;                              // Baud rate settings, clock divide by 2
    UCA0CTL1 &= ~UCSWRST;

    //P1SEL = BIT1 + BIT2 + BIT4;
    //P1SEL2 = BIT1 + BIT2 + BIT4;
    //UCA0CTL1 = UCSWRST;                       // **Put state machine in reset**
    //UCA0CTL0 |= UCCKPL + UCMSB + UCSYNC;      // 3-pin, 8-bit SPI master
    UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
    IE2 |= UCA0RXIE;                          // Enable USCI0 RX interrupt

     //__bis_SR_register(LPM4_bits + GIE);       // Enter LPM4, enable interrupt
}

volatile unsigned int color_val_1;
volatile unsigned int color_val_2;
volatile unsigned int color_val_3;
volatile unsigned int color_val_4;

void rainbow_spi(int color_val_1,  int color_val_2, int color_val_3,  int
color_val_4){
    // LED Code
    int i;
    int currentOff = 0;
    int counter = 0;
    int r_flag = 1;
    int g_flag = 0;
    int b_flag = 1;
    //int i;
//                       blue  green  red
    char leds[] = {0x00, 0x00, 0x00, 0x00,
                   0xF0, 0x00, 0x00, 0x00, // LIGHT 1
                   0xF0, 0x00, 0x00, 0x00, // LIGHT 2
                   0xF0, 0x00, 0x00, 0x00, // LIGHT 3
                   0xF0, 0x00, 0x00, 0x00, // LIGHT 4
                   0x00, 0x00, 0x00, 0x00};
    int beep = 0;
    SPI_setup();
    //wdt_disable();
    int color_val = 0;
       volatile int color_val_m[] =
{color_val_1,color_val_2,color_val_3,color_val_4};// array of each value
        for(i=0;i<4;i++){//for loop for amount of leds
            //this determins the rgb values
        if (color_val_m[i] > 1023){color_val_m[i] -= 1024;}//to stay within bpunds
        if (color_val_m[i] <= 255){leds[4*i+5] = color_val_m[i];}
        else if ((color_val_m[i] > 255)&&(color_val_m[i] <= 511)) {leds[4*i+5] = 511 - color_val_m[i];  }
        else if (color_val_m[i] > 511){leds[4*i+5] = 0x00;} // for blue values
        if (color_val_m[i] <= 255){leds[4*i+6] = 255- color_val_m[i];}
        else if ((color_val_m[i] > 255)&&(color_val_m[i] <= 511)) {leds[4*i+6] = 0x00;}
        else if (color_val_m[i] > 511){leds[4*i+6] = color_val_m[i]-511;} // for green values
        if (color_val_m[i] <= 255){leds[4*i+7] = 0x00;}
        else if ((color_val_m[i] > 255)&&(color_val_m[i] <= 511)) {leds[4*i+7] = -256 +color_val_m[i]; }
        else if ((color_val_m[i] > 511)&&(color_val_m[i] < 766 )){leds[4*i+7] = -color_val_m[i]+511;} // for red values
        else if (color_val_m[i] >= 766){
            leds[4*i+5] = 0;
            leds[4*i+6] = 0;
            leds[4*i+7] = 0;
            }
        }
      if ( beep == 1) { // Default on (1) or off (== 0)
        P2OUT |= BIT1;
        __delay_cycles(1000);
        P2OUT &= ~BIT1;
        __delay_cycles(1000);
      }
      for (i = 0; i <= sizeof(leds); i++) { // Send Color Frame
          while(!(IFG2 & UCA0TXIFG)); // Buffer ready?
              UCA0TXBUF = leds[i];
      }
}



int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	return 0;
} */
