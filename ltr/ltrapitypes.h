#ifndef LTRAPITYPES_H_
#define LTRAPITYPES_H_


#include "lwintypes.h"
#include "ltrapidefine.h"


#ifdef __cplusplus
extern "C" {
#endif


/*================================================================================================*/
#ifndef COMMENT_LENGTH
#define COMMENT_LENGTH (256)
#endif

#ifndef ADC_CALIBRATION_NUMBER
#define ADC_CALIBRATION_NUMBER (256)
#endif

#ifndef DAC_CALIBRATION_NUMBER
#define DAC_CALIBRATION_NUMBER (256)
#endif


/*================================================================================================*/
#pragma pack(4)

typedef struct {
    INT code;
    LPCSTR message;
} TLTR_ERROR_STRING_DEF;

/* Информация о типе крейта */
typedef struct {
    BYTE CrateType;                                        /* Тип крейта */
    BYTE CrateInterface;                                   /* Тип подключения крейта */
} TLTR_CRATE_INFO;
/* описание модуля */
typedef struct {
    BYTE CompanyName[16];
    BYTE DeviceName[16];                                   /* название изделия */
    BYTE SerialNumber[16];                                 /* серийный номер изделия */
    BYTE Revision;                                         /* ревизия изделия */
    BYTE Comment[COMMENT_LENGTH];
} TLTR_DESCRIPTION_MODULE;
/* описание процессора и програмного обеспечения */
typedef struct {
    BYTE Active;                                           /* флаг достоверности остальных полей
                                                            * структуры
                                                            */
    BYTE Name[16];                                         /* название */
    double ClockRate;
    DWORD FirmwareVersion;
    BYTE Comment[COMMENT_LENGTH];
} TLTR_DESCRIPTION_CPU;
/* описание ПЛИС */
typedef struct {
    BYTE Active;                                           /* флаг достоверности остальных полей
                                                            * структуры
                                                            */
    BYTE Name[16];                                         /* название */
    double ClockRate;
    DWORD FirmwareVersion;
    BYTE Comment[COMMENT_LENGTH];
} TLTR_DESCRIPTION_FPGA;
/* описание АЦП */
typedef struct {
    BYTE Active;                                           /* флаг достоверности остальных полей
                                                            * структуры
                                                            */
    BYTE Name[16];                                         /* название */
    double Calibration[ADC_CALIBRATION_NUMBER];            /* корректировочные коэффициенты */
    BYTE Comment[COMMENT_LENGTH];
} TLTR_DESCRIPTION_ADC;
/* описание ЦАП */
typedef struct {
    BYTE Active;                                           /* флаг достоверности остальных полей
                                                            * структуры
                                                            */
    BYTE Name[16];                                         /* название */
    double Calibration[DAC_CALIBRATION_NUMBER];            /* корректировочные коэффициенты */
    BYTE Comment[COMMENT_LENGTH];
} TLTR_DESCRIPTION_DAC ;
/* описание h-мезонинов */
typedef struct {
    BYTE Active;                                           /* флаг достоверности остальных полей
                                                            * структуры
                                                            */
    BYTE Name[16];                                         /* название изделия */
    BYTE SerialNumber[16];                                 /* серийный номер изделия */
    BYTE Revision;                                         /* ревизия изделия */
    double Calibration[4];                                 /* корректировочные коэффициенты */
    BYTE Comment[COMMENT_LENGTH];                          /* комментарий */
} TLTR_DESCRIPTION_MEZZANINE;
/* описание цифрового в/в */
typedef struct {
    BYTE Active;                                           /* флаг достоверности остальных полей
                                                            * структуры
                                                            */
    BYTE Name[16];                                         /* название */
    WORD InChannels;                                       /* число каналов */
    WORD OutChannels;                                      /* число каналов */
    BYTE Comment[COMMENT_LENGTH];
} TLTR_DESCRIPTION_DIGITAL_IO;
/* описание интерфейсных модулей */
typedef struct _DESCRIPTION_INTERFACE_ {
    BYTE Active;                                           /* флаг достоверности остальных полей
                                                            * структуры
                                                            */
    BYTE Name[16];                                         /* название */
    BYTE Comment[COMMENT_LENGTH];
} TLTR_DESCRIPTION_INTERFACE;

/* элемент списка IP-крейтов */
typedef struct _IPCRATE_ENTRY_ {
    DWORD ip_addr;                                         /* IP адрес (host-endian) */
    DWORD flags;                                           /* флаги режимов (CRATE_IP_FLAG_...) */
    CHAR serial_number[16];                                /* серийный номер
                                                            * (если крейт подключен)
                                                            */
    BYTE is_dynamic;                                       /* 0 = задан пользователем,
                                                            * 1 = найден автоматически
                                                            */
    BYTE status;                                           /* состояние (CRATE_IP_STATUS_...) */
} TLTR_CRATE_IP_ENTRY;

typedef struct {
    DWORD size;                                            /* размер струкуры */
    DWORD flags;                                           /* флаги */
    WORD crate_type;                                       /* тип крейта из CRATE_TYPE_XXX */
    WORD crate_intf;                                       /* интерфейс, по которому подключен
                                                              крейт (из CRATE_IFACE_XXX) */
    WORD crate_state;
    WORD crate_mode;                                       /* режим работы крейта (из LTR_CRATE_MODE_XXX) */
    ULONGLONG con_time;                                    /* время установления соединения
                                                              с крейтом (формат unixtime) */
    WORD res[11];
    WORD modules_cnt;                                      /* количество слотов в крейте */
    WORD mids[LTR_MODULES_PER_CRATE_MAX];                  /* id-модулей для всех слотов */
    WORD res2[3*LTR_MODULES_PER_CRATE_MAX];
    WORD ctl_clients_cnt;                                  /* количество клиентов, подключенных по
                                                            * управляющему каналу к крейту
                                                            */
    WORD total_mod_clients_cnt;                            /* количество клиентов,
                                                            * подключенные ко всем модулям
                                                            */
    DWORD res3[11];

    ULONGLONG wrd_sent;                                    /* передано слов крейту */
    ULONGLONG wrd_recv;                                    /* слов принято от крейта
                                                            * и его модулей
                                                            */
    double bw_send;                                        /* скорость передачи слов */
    double bw_recv;                                        /* скорость приема слов */
    ULONGLONG crate_wrd_recv;                                  /* количество управляющих слов
                                                            * непосредственно от крейта
                                                            */
    ULONGLONG internal_rbuf_miss;                          /* количество потерянных буферов
                                                            * из-за внутреннего переполнения
                                                            */
    DWORD internal_rbuf_ovfls;                             /* количество переполнений
                                                            * внутреннго буфера крейта
                                                            */
    DWORD rbuf_ovfls;                                      /* количество переполнений буфера
                                                            * для модулей крейта
                                                            */
    DWORD total_start_marks;                               /* кол-во меток старта как от крейта,
                                                            * так и от модулей
                                                            */
    DWORD total_sec_marks;                                 /* кол-во секундных меток как от крейта,
                                                            * так и от модулей
                                                            */
    DWORD crate_start_marks;                               /* кол-во меток старта
                                                            * непосредственно от крейта
                                                            */
    DWORD crate_sec_marks;                                 /* кол-во секундных меток
                                                            * непосредственно от крейта
                                                            */
    ULONGLONG crate_unixtime;                              /* последнее значение расширенной
                                                            * секундной метки (формат unixtime)
                                                            */
    DWORD therm_mask;                                      /**< маска действительных показаний термометров */
    float therm_vals[LTR_CRATE_THERM_MAX_CNT];             /**< значение показаний термометров крейта */


    DWORD res4[19];
} TLTR_CRATE_STATISTIC;

typedef struct {
    DWORD size;                                            /* размер структуры */
    WORD client_cnt;                                       /* количество клиентов */
    WORD mid;                                              /* ID-модуля */
    DWORD flags;                                           /* флаги */
    CHAR  name[LTR_MODULE_NAME_SIZE];                      /* название модуля (возможно с модификациями) */
    DWORD res[5];
    ULONGLONG wrd_sent;                                    /* кол-во переданных слов модулю */
    ULONGLONG wrd_recv;                                    /* кол-во принятых слов от модуля */
    double bw_send;                                        /* скорость передачи слов */
    double bw_recv;                                        /* скорость приема слов */
    ULONGLONG wrd_sent_to_client;                          /* сколько слов передано клиенту */
    ULONGLONG wrd_recv_from_client;                        /* сколько слов принято от клиентов */
    ULONGLONG wrd_recv_drop;                               /* сколько выкинуто слов
                                                            * из-за переполнения
                                                            */
    DWORD rbuf_ovfls;                                      /* количество переполнений
                                                            * буфера на прием
                                                            */
    DWORD send_srvbuf_size;                                /* размер буфера для модуля
                                                            * на передачу
                                                            */
    DWORD recv_srvbuf_size;                                /* размер буфера для модуля на прием */
    DWORD send_srvbuf_full;                                /* на сколько слов заполнен
                                                            * буфер на передачу
                                                            */
    DWORD recv_srvbuf_full;                                /* на сколько слов заполнен
                                                            * буфер на прием
                                                            */
    DWORD send_srvbuf_full_max;                            /* на сколько слов был
                                                            * максимально заполнен буфер на передачу
                                                            */
    DWORD recv_srvbuf_full_max;                            /* на сколько слов был
                                                            * максимально заполнен буфер на прием
                                                            */
    DWORD res2[17];                                        /* резерв */
    DWORD start_mark;                                      /* количество меток старт от модуля */
    DWORD sec_mark;                                        /* количество секундных меток
                                                            * от модуля
                                                            */
    /* Поля, описывающие состояние внутренней аппаратной очереди модуля.
     * Действительны, только если есть флаг LTR_MODULE_FLAGS_USE_HARD_SEND_FIFO
     */
    DWORD hard_send_fifo_size;                             /* Размер аппаратной очереди */
    DWORD hard_send_fifo_unack_words;                      /* Заполненность аппаратной очереди
                                                            * (количество отправленных,
                                                            * но не подтвержденных слов)
                                                            */
    DWORD hard_send_fifo_underrun;                         /* Количество голоданий очереди
                                                            * после последнего сброса
                                                            */
    DWORD hard_send_fifo_overrun;                          /* Количество переполнений очереди
                                                            * после последнего сброса
                                                            */
    DWORD hard_send_fifo_internal;                         /* Внутренне состояние
                                                            * аппаратной очереди
                                                            */

    DWORD res3[25];                                        /* резерв */
} TLTR_MODULE_STATISTIC;

/* информация об устройстве и прошивке */
typedef struct {
    DWORD size;
    char devname[LTR_CRATE_DEVNAME_SIZE];                  /**< название устройства */
    char serial[LTR_CRATE_SERIAL_SIZE];                    /**< серийный номер */
    char soft_ver[LTR_CRATE_SOFTVER_SIZE];                 /**< версия прошивки */
    char brd_revision[LTR_CRATE_REVISION_SIZE];            /**< ревизия платы */
    char brd_impl[LTR_CRATE_IMPLEMENTATION_SIZE];          /**< опции платы */
    char bootloader_ver[LTR_CRATE_BOOTVER_SIZE];           /**< версия загрузчика */
    char cpu_type[LTR_CRATE_CPUTYPE_SIZE];                 /**< тип микроконтроллера */
    char fpga_name[LTR_CRATE_FPGA_NAME_SIZE];
    char fpga_version[LTR_CRATE_FPGA_VERSION_SIZE];
    char crate_type_name[LTR_CRATE_TYPE_NAME];
    char spec_info[LTR_CRATE_SPECINFO_SIZE];               /**< резерв */
    BYTE protocol_ver_major;                               /**< версия протокола между
                                                            * сервером и крейтом (мажорная)
                                                            */
    BYTE protocol_ver_minor;                               /**< версия протокола между
                                                            * сервером и крейтом (минорная)
                                                            */
    BYTE slots_config_ver_major;                           /**< версия протокола для сохранения
                                                            * настроек модуля (мажорная)
                                                            */
    BYTE slots_config_ver_minor;                           /**< версия протокола для сохранения
                                                            * настроек модуля (минорная)
                                                            */
} TLTR_CRATE_DESCR;

#pragma pack()

typedef INT TLTR_CARD_START_MODE;

#ifdef __cplusplus
}
#endif

#endif /*#ifndef LTRAPITYPES_H_*/
