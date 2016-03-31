#ifndef LTRAPIDEFINE_H_
#define LTRAPIDEFINE_H_


/*============================================================================*/
#define LTRD_ADDR_LOCAL   (0x7F000001l)
#define LTRD_ADDR_DEFAULT (LTRD_ADDR_LOCAL)
#define LTRD_PORT_DEFAULT (11111)



#define LTR_CRATES_MAX             16l /* Максимальное количество крейтов,
                                          которое можно получить с помощью
                                          функции LTR_GetCrates(). Для ltrd
                                          можно получить список большего кол-ва
                                          крейтов с помощью LTR_GetCratesWithInfo() */
#define LTR_MODULES_PER_CRATE_MAX  16l /* Максимальное количество модулей в одном крейте */


/* Фиктивный серийный номер крейта для управления самим сервером
 * (работает и тогда, когда нет ни одного подключенного крейта
 * Команды, которые рассчитаны на этот режим, помечены комментарием "SERVER_CONTROL"
 */
#define LTR_CSN_SERVER_CONTROL              "#SERVER_CONTROL"



/* типы каналов клиент-сервер */
#define LTR_CC_CHNUM_CONTROL                 0  /* канал для передачи управляющих запросов крейту или ltrd*/
#define LTR_CC_CHNUM_MODULE1                 1  /* канал для работы c модулем в слоте 1 */
#define LTR_CC_CHNUM_MODULE2                 2  /* канал для работы c модулем в слоте 2 */
#define LTR_CC_CHNUM_MODULE3                 3  /* канал для работы c модулем в слоте 3 */
#define LTR_CC_CHNUM_MODULE4                 4  /* канал для работы c модулем в слоте 4 */
#define LTR_CC_CHNUM_MODULE5                 5  /* канал для работы c модулем в слоте 5 */
#define LTR_CC_CHNUM_MODULE6                 6  /* канал для работы c модулем в слоте 6 */
#define LTR_CC_CHNUM_MODULE7                 7  /* канал для работы c модулем в слоте 7 */
#define LTR_CC_CHNUM_MODULE8                 8  /* канал для работы c модулем в слоте 8 */
#define LTR_CC_CHNUM_MODULE9                 9  /* канал для работы c модулем в слоте 9 */
#define LTR_CC_CHNUM_MODULE10               10  /* канал для работы c модулем в слоте 10 */
#define LTR_CC_CHNUM_MODULE11               11  /* канал для работы c модулем в слоте 11 */
#define LTR_CC_CHNUM_MODULE12               12  /* канал для работы c модулем в слоте 12 */
#define LTR_CC_CHNUM_MODULE13               13  /* канал для работы c модулем в слоте 13 */
#define LTR_CC_CHNUM_MODULE14               14  /* канал для работы c модулем в слоте 14 */
#define LTR_CC_CHNUM_MODULE15               15  /* канал для работы c модулем в слоте 15 */
#define LTR_CC_CHNUM_MODULE16               16  /* канал для работы c модулем в слоте 16 */
#define LTR_CC_CHNUM_USERDATA               18  /* канал для работы с псевдомодулем для
                                                 * пользовательских данных
                                                 */
#define LTR_CC_FLAG_RAW_DATA             0x4000 /* флаг отладки - ltrd передает клиенту
                                                 * все данные, которые приходят от крейта,
                                                 * без разбивки по модулям
                                                 */

#define LTR_CC_IFACE_USB                 0x0100  /* явное указание, что соединение должно быть
                                                  * по USB-интерфейсу
                                                  */
#define LTR_CC_IFACE_ETH                 0x0200  /* явное указание, что соединение должно быть
                                                  * по Ethernet (TCP/IP)
                                                  */

#define LTR_CC_CHNUM(cc)        ((cc) & 0x00FF)
#define LTR_CC_IFACE(cc)        ((cc) & 0x0F00)
#define LTR_CC_FLAGS(cc)        ((cc) & 0xF000)

#define LTR_FLAG_RBUF_OVF             (1u<<0)     /* флаг переполнения буфера клиента */
#define LTR_FLAG_RFULL_DATA           (1u<<1)     /* флаг получения данных в полном формате
                                                   * в функции LTR_GetCrateRawData
                                                   */

/* идентификаторы модулей */
#define LTR_MID_EMPTY                 0                /* пустой слот */
#define LTR_MID_IDENTIFYING           0xFFFF           /* модуль в процессе определения ID */

#define LTR_MID_MODULE(x)             (((x) & 0xFF) | (((x) & 0xFF) << 8))
#define LTR_MID_LTR01                 LTR_MID_MODULE(1)   /* идентификатор модуля LTR01 */
#define LTR_MID_LTR11                 LTR_MID_MODULE(11)  /* идентификатор модуля LTR11 */
#define LTR_MID_LTR22                 LTR_MID_MODULE(22)  /* идентификатор модуля LTR22 */
#define LTR_MID_LTR24                 LTR_MID_MODULE(24)  /* идентификатор модуля LTR24 */
#define LTR_MID_LTR25                 LTR_MID_MODULE(25)  /* идентификатор модуля LTR25 */
#define LTR_MID_LTR27                 LTR_MID_MODULE(27)  /* идентификатор модуля LTR27 */
#define LTR_MID_LTR34                 LTR_MID_MODULE(34)  /* идентификатор модуля LTR34 */
#define LTR_MID_LTR35                 LTR_MID_MODULE(35)  /* идентификатор модуля LTR35 */
#define LTR_MID_LTR41                 LTR_MID_MODULE(41)  /* идентификатор модуля LTR41 */
#define LTR_MID_LTR42                 LTR_MID_MODULE(42)  /* идентификатор модуля LTR42 */
#define LTR_MID_LTR43                 LTR_MID_MODULE(43)  /* идентификатор модуля LTR43 */
#define LTR_MID_LTR51                 LTR_MID_MODULE(51)  /* идентификатор модуля LTR51 */
#define LTR_MID_LTR114                LTR_MID_MODULE(114) /* идентификатор модуля LTR114 */
#define LTR_MID_LTR210                LTR_MID_MODULE(210) /* идентификатор модуля LTR210 */
#define LTR_MID_LTR212                LTR_MID_MODULE(212) /* идентификатор модуля LTR212 */

/* тип крейта (для TCRATE_INFO) */
#define LTR_CRATE_TYPE_UNKNOWN                      0
#define LTR_CRATE_TYPE_LTR010                       10
#define LTR_CRATE_TYPE_LTR021                       21
#define LTR_CRATE_TYPE_LTR030                       30
#define LTR_CRATE_TYPE_LTR031                       31
#define LTR_CRATE_TYPE_LTR032                       32
#define LTR_CRATE_TYPE_LTR_CU_1                     40
#define LTR_CRATE_TYPE_LTR_CEU_1                    41
#define LTR_CRATE_TYPE_BOOTLOADER                   99

/* интерфейс крейта (для TCRATE_INFO) */
#define LTR_CRATE_IFACE_UNKNOWN                     0
#define LTR_CRATE_IFACE_USB                         1
#define LTR_CRATE_IFACE_TCPIP                       2

/* состояние крейта (для TIPCRATE_ENTRY) */
#define LTR_CRATE_IP_STATUS_OFFLINE                 0
#define LTR_CRATE_IP_STATUS_CONNECTING              1
#define LTR_CRATE_IP_STATUS_ONLINE                  2
#define LTR_CRATE_IP_STATUS_ERROR                   3

/* флаги параметров крейта (для TIPCRATE_ENTRY и команды CONTROL_COMMAND_IP_SET_FLAGS) */
#define LTR_CRATE_IP_FLAG_AUTOCONNECT               0x00000001
#define LTR_CRATE_IP_FLAG__VALID_BITS_              0x00000001





#define LTR_MODULE_NAME_SIZE                16

#define LTR_CRATE_DEVNAME_SIZE              32
#define LTR_CRATE_SERIAL_SIZE               16
#define LTR_CRATE_SOFTVER_SIZE              32
#define LTR_CRATE_REVISION_SIZE             16
#define LTR_CRATE_IMPLEMENTATION_SIZE       16
#define LTR_CRATE_BOOTVER_SIZE              16
#define LTR_CRATE_CPUTYPE_SIZE              16
#define LTR_CRATE_TYPE_NAME                 16
#define LTR_CRATE_SPECINFO_SIZE             48

#define LTR_CRATE_FPGA_NAME_SIZE            32
#define LTR_CRATE_FPGA_VERSION_SIZE         32

#define LTR_CRATE_THERM_MAX_CNT              8 /**< Максимальное кол-во термометров
                                                    в крейте, показания которых отображаются в статистике */

#define LTR_MODULE_FLAGS_HIGH_BAUD          0x0001    /** признак, что модуль использует
                                                       * высокую скорость
                                                       */
#define LTR_MODULE_FLAGS_USE_HARD_SEND_FIFO 0x0100    /** признак, что модуль использует статистику
                                                       * внутреннего аппаратного FIFO на передачу
                                                       * данных
                                                       */
#define LTR_MODULE_FLAGS_USE_SYNC_MARK      0x0200    /** признак, что модуль поддерживает
                                                       * генерирование синхрометок */

#define LTR_CARD_START_OFF (0)
#define LTR_CARD_START_RUN (1)
/*================================================================================================*/


/*================================================================================================*/
typedef enum {
    LTR_CRATE_MODE_BOOTLOADER = 1,
    LTR_CRATE_MODE_APPLICATION = 2,
    LTR_CRATE_MODE_CONTROL = 3
} e_LTR_CRATE_MODE;


/** @brief Состояние ПЛИС */
typedef enum {
    LTR_FPGA_STATE_NO_POWER       = 0x0, /**< Нет сигнала питания ПЛИС */
    LTR_FPGA_STATE_NSTATUS_TOUT   = 0x1, /**< Истекло время ожидания готовности
                                                ПЛИС к загрузке */
    LTR_FPGA_STATE_CONF_DONE_TOUT = 0x2, /**< Истекло время ожидания завершения
                                                загрузки ПЛИС (обычно означает,
                                                что во Flash нет действительной
                                                прошивки) */
    LTR_FPGA_STATE_LOAD_PROGRESS  = 0x3, /**< Идет загрузка ПЛИС */
    LTR_FPGA_STATE_POWER_ON       = 0x4, /**< Состояние после POWER_ON. Свидетельсвует
                                              о том, что было неожиданное снятие питания */
    LTR_FPGA_STATE_LOAD_DONE      = 0x7, /**< Загрузка ПЛИС завершена,
                                                но работа ПЛИС еще не разрешена */
    LTR_FPGA_STATE_WORK           = 0xF  /**< Нормальное рабочее состояние ПЛИС */
} e_LTR_FPGA_STATE;
/*================================================================================================*/

#endif /*#ifndef LTRAPIDEFINE_H_*/
