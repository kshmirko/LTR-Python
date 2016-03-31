/*
 * common part
 */
#ifndef LTRAPI_H_
#define LTRAPI_H_

#include "ltrapitypes.h"
#ifndef LTRAPI_DISABLE_COMPAT_DEFS
    #include "ltrapi_compat_defs.h"
#endif

/*================================================================================================*/
#ifdef _WIN32
    #ifdef LTRAPIWIN_EXPORTS
      #define LTRAPIWIN_DllExport(type)   __declspec(dllexport) type APIENTRY
    #else
      #define LTRAPIWIN_DllExport(type)   __declspec(dllimport) type APIENTRY
    #endif
#elif defined __GNUC__
    #define LTRAPIWIN_DllExport(type) __attribute__ ((visibility("default"))) type
#else
    #define LTRAPIWIN_DllExport(type) type
#endif


/* коды ошибок */
#define LTR_OK                            ( 0l)     /*Выполнено без ошибок.*/
#define LTR_ERROR_UNKNOWN                 (-1l)     /*Неизвестная ошибка.*/
#define LTR_ERROR_PARAMETERS              (-2l)     /*Ошибка входных параметров.*/
#define LTR_ERROR_PARAMETRS               LTR_ERROR_PARAMETERS
#define LTR_ERROR_MEMORY_ALLOC            (-3l)     /*Ошибка динамического выделения памяти.*/
#define LTR_ERROR_OPEN_CHANNEL            (-4l)     /*Ошибка открытия канала обмена с сервером.*/
#define LTR_ERROR_OPEN_SOCKET             (-5l)     /*Ошибка открытия сокета.*/
#define LTR_ERROR_CHANNEL_CLOSED          (-6l)     /*Ошибка. Канал обмена с сервером не создан.*/
#define LTR_ERROR_SEND                    (-7l)     /*Ошибка отправления данных.*/
#define LTR_ERROR_RECV                    (-8l)     /*Ошибка приема данных.*/
#define LTR_ERROR_EXECUTE                 (-9l)     /*Ошибка обмена с крейт-контроллером.*/
#define LTR_WARNING_MODULE_IN_USE         (-10l)    /*Канал обмена с сервером создан в текущей программе
                                                     и в какой - то еще*/

#define LTR_ERROR_NOT_CTRL_CHANNEL        (-11l)    /* Номер канала для этой операции должен быть CC_CONTROL */
#define LTR_ERROR_SRV_INVALID_CMD         (-12l)    /* Команда не поддерживается сервером */
#define LTR_ERROR_SRV_INVALID_CMD_PARAMS  (-13l)    /* Сервер не поддерживает указанные параметры команды */
#define LTR_ERROR_INVALID_CRATE           (-14l)    /* Указанный крейт не найден */
#define LTR_ERROR_EMPTY_SLOT              (-15l)    /* В указанном слоте отсутствует модуль */
#define LTR_ERROR_UNSUP_CMD_FOR_SRV_CTL   (-16l)    /* Команда не поддерживается управляющим каналом сервера */
#define LTR_ERROR_INVALID_IP_ENTRY        (-17l)    /* Неверная запись сетевого адреса крейта */
#define LTR_ERROR_NOT_IMPLEMENTED         (-18l)    /* Данная возможность не реализована */
#define LTR_ERROR_CONNECTION_CLOSED       (-19l)    /* Соединение было закрыто сервером */

#define LTR_ERROR_INVALID_MODULE_DESCR    (-40l)    /* Неверный описатель модуля */
#define LTR_ERROR_INVALID_MODULE_SLOT     (-41l)    /* Указан неверный слот для модуля */
#define LTR_ERROR_INVALID_MODULE_ID       (-42l)    /* Неверный ID-модуля в ответе на сброс */
#define LTR_ERROR_NO_RESET_RESPONSE       (-43l)    /* Нет ответа на команду сброс */
#define LTR_ERROR_SEND_INSUFFICIENT_DATA  (-44l)    /* Передано данных меньше, чем запрашивалось */
#define LTR_ERROR_RECV_INSUFFICIENT_DATA  (-45l)
#define LTR_ERROR_NO_CMD_RESPONSE         (-46l)    /* Нет ответа на команду сброс */
#define LTR_ERROR_INVALID_CMD_RESPONSE    (-47l)    /* Пришел неверный ответ на команду */
#define LTR_ERROR_INVALID_RESP_PARITY     (-48l)    /* Неверный бит четности в пришедшем ответе */
#define LTR_ERROR_INVALID_CMD_PARITY      (-49l)    /* Ошибка четности переданной команды */
#define LTR_ERROR_UNSUP_BY_FIRM_VER       (-50l)    /* Возможность не поддерживается данной версией прошивки */
#define LTR_ERROR_MODULE_STARTED          (-51l)    /* Модуль уже запущен */
#define LTR_ERROR_MODULE_STOPPED          (-52l)    /* Модуль остановлен */
#define LTR_ERROR_RECV_OVERFLOW           (-53l)    /* Произошло переполнение буфера */
#define LTR_ERROR_FIRM_FILE_OPEN          (-54l)    /* Ошибка открытия файла прошивки */
#define LTR_ERROR_FIRM_FILE_READ          (-55l)    /* Ошибка чтения файла прошивки */
#define LTR_ERROR_FIRM_FILE_FORMAT        (-56l)    /* Ошибка формата файла прошивки */
#define LTR_ERROR_FPGA_LOAD_READY_TOUT    (-57l)    /* Превышен таймаут ожидания готовности ПЛИС к загрузке */
#define LTR_ERROR_FPGA_LOAD_DONE_TOUT     (-58l)    /* Превышен таймаут ожидания перехода ПЛИС в рабочий режим */
#define LTR_ERROR_FPGA_IS_NOT_LOADED      (-59l)    /* Прошивка ПЛИС не загружена */
#define LTR_ERROR_FLASH_INVALID_ADDR      (-60l)    /* Неверный адрес Flash-памяти */
#define LTR_ERROR_FLASH_WAIT_RDY_TOUT     (-61l)    /* Превышен таймаут ожидания завершения записи/стирания Flash-памяти */
#define LTR_ERROR_FIRSTFRAME_NOTFOUND     (-62l)    /* First frame in card data stream not found */
#define LTR_ERROR_CARDSCONFIG_UNSUPPORTED (-63l)
#define LTR_ERROR_FLASH_OP_FAILED         (-64l)    /* Ошибка выполненя операции с flash-памятью */
#define LTR_ERROR_FLASH_NOT_PRESENT       (-65l)    /* Flash-память не обнаружена */
#define LTR_ERROR_FLASH_UNSUPPORTED_ID    (-66l)    /* Обнаружен неподдерживаемый тип flash-памяти */
#define LTR_ERROR_FLASH_UNALIGNED_ADDR    (-67l)    /* Невыровненный адрес flash-памяти */
#define LTR_ERROR_FLASH_VERIFY            (-68l)    /* Ошибка при проверки записанных данных во flash-память */
#define LTR_ERROR_FLASH_UNSUP_PAGE_SIZE   (-69l)    /* Установлен неподдерживаемый размер страницы flash-памяти */
#define LTR_ERROR_FLASH_INFO_NOT_PRESENT  (-70l)    /* Отсутствует информация о модуле во Flash-памяти */
#define LTR_ERROR_FLASH_INFO_UNSUP_FORMAT (-71l)    /* Неподдерживаемый формат информации о модуле во Flash-памяти */
#define LTR_ERROR_FLASH_SET_PROTECTION    (-72l)    /* Не удалось установить защиту Flash-памяти */
#define LTR_ERROR_FPGA_NO_POWER           (-73l)    /* Нет питания микросхемы ПЛИС */
#define LTR_ERROR_FPGA_INVALID_STATE      (-74l)    /* Не действительное состояние загрузки ПЛИС */
#define LTR_ERROR_FPGA_ENABLE             (-75l)    /* Не удалось перевести ПЛИС в разрешенное состояние */
#define LTR_ERROR_FPGA_AUTOLOAD_TOUT      (-76l)    /* Истекло время ожидания автоматической загрузки ПЛИС */
#define LTR_ERROR_PROCDATA_UNALIGNED      (-77l)    /* Обрабатываемые данные не выравнены на границу кадра */
#define LTR_ERROR_PROCDATA_CNTR           (-78l)    /* Ошибка счетчика в обрабатываемых данных */
#define LTR_ERROR_PROCDATA_CHNUM          (-79l)    /* Неверный номер канала в обрабатываемых данных */
#define LTR_ERROR_PROCDATA_WORD_SEQ       (-80l)    /* Неверная последовательность слов в обрабатываемых данных */
#define LTR_ERROR_FLASH_INFO_CRC          (-81l)    /* Неверная контрольная сумма в записанной информации о модуле */

#define LTR_OPENINFLG_REOPEN (0x01ul)
#define LTR_OPENOUTFLG_REOPEN (0x01ul)

#define LTR_DEFAULT_SEND_RECV_TIMEOUT   10000UL


/*================================================================================================*/
/* Значения для управления ножками процессора, доступными для пользовательского программирования */
enum en_LTR_UserIoCfg {
    LTR_USERIO_DIGIN1   = 1,    /* ножка является входом и подключена к DIGIN1 */
    LTR_USERIO_DIGIN2   = 2,    /* ножка является входом и подключена к DIGIN2 */
    LTR_USERIO_DIGOUT   = 0,    /* ножка является выходом (подключение см. en_LTR_DigOutCfg) */
    LTR_USERIO_DEFAULT  = LTR_USERIO_DIGOUT
};

/* Значения для управления выходами DIGOUTx */
enum en_LTR_DigOutCfg {
    LTR_DIGOUT_CONST0   = 0x00, /* постоянный уровень логического "0" */
    LTR_DIGOUT_CONST1   = 0x01, /* постоянный уровень логической "1" */
    LTR_DIGOUT_USERIO0  = 0x02, /* выход подключен к ножке userio0 (PF1 в рев. 0, PF1 в рев. 1) */
    LTR_DIGOUT_USERIO1  = 0x03, /* выход подключен к ножке userio1 (PG13) */
    LTR_DIGOUT_DIGIN1   = 0x04, /* выход подключен ко входу DIGIN1 */
    LTR_DIGOUT_DIGIN2   = 0x05, /* выход подключен ко входу DIGIN2 */
    LTR_DIGOUT_START    = 0x06, /* на выход подаются метки "СТАРТ" */
    LTR_DIGOUT_SECOND   = 0x07, /* на выход подаются метки "СЕКУНДА" */
    LTR_DIGOUT_IRIG     = 0x08, /* контроль сигналов точного времени IRIG
                                    (digout1: готовность, digout2: секунда) */
    LTR_DIGOUT_DEFAULT  = LTR_DIGOUT_CONST0
};

/* Значения для управления метками "СТАРТ" и "СЕКУНДА" */
enum en_LTR_MarkMode {
    LTR_MARK_OFF                = 0x00, /* метка отключена */
    LTR_MARK_EXT_DIGIN1_RISE    = 0x01, /* метка по фронту DIGIN1 */
    LTR_MARK_EXT_DIGIN1_FALL    = 0x02, /* метка по спаду DIGIN1 */
    LTR_MARK_EXT_DIGIN2_RISE    = 0x03, /* метка по фронту DIGIN2 */
    LTR_MARK_EXT_DIGIN2_FALL    = 0x04, /* метка по спаду DIGIN2 */

    /* Внутренняя генерация метки крейт-контроллером
       "СТАРТ"      : вставляется однократно при вызове LTR_MakeStartMark
       "СЕКУНДА"    : по таймеру, начиная с вызова LTR_StartSecondMark */
    LTR_MARK_INTERNAL           = 0x05,

    /* Источник метки - вход NAMUR (только для LTR-E-7/15) */
    LTR_MARK_NAMUR1_LO2HI       = 8,    /* по сигналу NAMUR1 (START_IN), возрастание тока */
    LTR_MARK_NAMUR1_HI2LO       = 9,    /* по сигналу NAMUR1 (START_IN), спад тока */
    LTR_MARK_NAMUR2_LO2HI       = 10,   /* по сигналу NAMUR2 (M1S_IN), возрастание тока */
    LTR_MARK_NAMUR2_HI2LO       = 11,   /* по сигналу NAMUR2 (M1S_IN), спад тока */

    /* Источник метки - декодер сигналов точного времени IRIG-B006
       IRIG может использоваться только для меток "СЕКУНДА", для "СТАРТ" игнорируется */
    LTR_MARK_SEC_IRIGB_DIGIN1   = 16,   // со входа DIGIN1, прямой сигнал
    LTR_MARK_SEC_IRIGB_nDIGIN1  = 17,   // со входа DIGIN1, инвертированный сигнал
    LTR_MARK_SEC_IRIGB_DIGIN2   = 18,   // со входа DIGIN2, прямой сигнал
    LTR_MARK_SEC_IRIGB_nDIGIN2  = 19,   // со входа DIGIN2, инвертированный сигнал
    };

enum en_LTR_LogLevel {
    LTR_LOGLVL_ERR_FATAL    = 0,
    LTR_LOGLVL_ERR          = 1,
    LTR_LOGLVL_WARN         = 2,
    LTR_LOGLVL_INFO         = 3,
    LTR_LOGLVL_DETAIL       = 4,
    LTR_LOGLVL_DBG_HIGH     = 5,
    LTR_LOGLVL_DBG_MED      = 6,
    LTR_LOGLVL_DBG_LOW      = 7
};

enum en_LTR_CrateThermNum {
    LTR_CRATE_THERM_LOWER = 0, /**< Нижний датчик темперетуры */
    LTR_CRATE_THERM_UPPER = 1  /**< Верхний датчик темперетуры */
};

typedef enum {
    /* Интервал опроса крейта, для проверки, рабочее ли подключение (в мс) */
    LTR_SERVER_PARAM_ETH_CRATE_POLL_TIME   = 0x100,
    /* Таймаут на установление соединения с крейтом (в мс) */
    LTR_SERVER_PARAM_ETH_CRATE_CON_TOUT    = 0x101,
    /* Таймаут на ответ на управляющую команду от крейта (в мс) */
    LTR_SERVER_PARAM_ETH_CRATE_CTLCMD_TOUT = 0x102,
    /* Интервал проверки адресов хоста для запуска автоподключения (в мс) */
    LTR_SERVER_PARAM_ETH_INTF_CHECK_TIME   = 0x103
} t_ltr_server_params;


#pragma pack(4)

typedef struct {
    unsigned int saddr;                       /* сетевой адрес сервера */
    unsigned short  sport;                       /* сетевой порт сервера */
    char  csn[LTR_CRATE_SERIAL_SIZE];  /* серийный номер крейта */
    unsigned short  cc;                          /* номер канала крейта */
    unsigned int flags;                       /* флаги состояния канала */
    unsigned int tmark;                       /* последняя принятая метка времени */

    LPVOID Internal;                   /* указатель на канал */
} TLTR;

/* Структура конфигурации LTR-EU */
typedef struct {
    /* Настройка ножек процессора
     * [0] PF1 в рев. 0, PF1 в рев. 1+
     * [1] PG13
     * [2] PF3, только рев. 1+, только вход
     * [3] резерв
     */
    WORD        userio[4];          /* одно из значений LTR_USERIO_... */

    /* Настройка выходов DIGOUTx */
    WORD        digout[2];          /* конфигурация выходов (LTR_DIGOUT_...) */
    WORD        digout_en;          /* разрешение выходов DIGOUT1, DIGOUT2 */
} TLTR_CONFIG;

typedef struct {
    WORD size;
    BYTE autorun_ison;
} TLTR_SETTINGS;

#pragma pack()


/*================================================================================================*/
#ifdef __cplusplus
extern "C" {
#endif
/* -- Функции для внутреннего применения -- */
LTRAPIWIN_DllExport(INT) LTR__GenericCtlFunc(TLTR *ltr, LPCVOID request_buf, DWORD request_size,
    LPVOID reply_buf, DWORD reply_size, INT ack_error_code, DWORD timeout);

/* -- Функции общего назначения -- */
/* Инициализация управляющей структуры TLTR */
LTRAPIWIN_DllExport(INT) LTR_Init(TLTR *ltr);
/* Открытие соединения с крейтом */
LTRAPIWIN_DllExport(INT) LTR_Open(TLTR *ltr);

LTRAPIWIN_DllExport(INT) LTR_OpenEx(TLTR *ltr, DWORD timeout);
/* Закрытие соединения с крейтом */
LTRAPIWIN_DllExport(INT) LTR_Close(TLTR *ltr);
/* Проверка, установлено ли соединение с крейтом */
LTRAPIWIN_DllExport(INT) LTR_IsOpened(TLTR *ltr);
/* Получение текстового сообщения об ошибке по ее коду */
LTRAPIWIN_DllExport(LPCSTR) LTR_GetErrorString(INT error);


/* -- Функции низкого уровня -- */
/* Прием данных из крейта */
LTRAPIWIN_DllExport(INT) LTR_Recv(TLTR *ltr, DWORD *data, DWORD *tmark, DWORD size, DWORD timeout);
// Посылка данных в крейт
LTRAPIWIN_DllExport(INT) LTR_Send(TLTR *ltr, const DWORD *data, DWORD size, DWORD timeout);
/* Прием данных из крейта с чтением массива меток времени в формате 64-бит unixtime */
LTRAPIWIN_DllExport(INT) LTR_RecvEx(TLTR *ltr, DWORD *data, DWORD *tmark, DWORD size,
                                    DWORD timeout, LONGLONG *unixtime);

/* Чтение последней принятой и обработанной метки unixtime (0, если таких меток не было) */
LTRAPIWIN_DllExport(INT) LTR_GetLastUnixTimeMark(TLTR *ltr, LONGLONG* unixtime);

/* -- Функции, работающие с управляющим каналом крейт-контроллера
 * -- (должен быть открыт CC_CONTROL)
 */
/* Получение списка крейтов, подключенных к серверу */
LTRAPIWIN_DllExport(INT) LTR_GetCrates(TLTR *ltr, BYTE *csn);
/* Получение списка модулей в крейте */
LTRAPIWIN_DllExport(INT) LTR_GetCrateModules(TLTR *ltr, WORD *mid);
/* Управление приоритетом процесса ltrserver.exe */
LTRAPIWIN_DllExport(INT) LTR_SetServerProcessPriority(TLTR *ltr, DWORD Priority);
/* Чтение описания крейта (модель, тип интерфейса) */
LTRAPIWIN_DllExport(INT) LTR_GetCrateInfo(TLTR *ltr, TLTR_CRATE_INFO *CrateInfo);
/* Получение сырых данных из крейта (если был установлен CC_RAW_DATA_FLAG) */
LTRAPIWIN_DllExport(INT) LTR_GetCrateRawData(TLTR *ltr, DWORD *data, DWORD *tmark, DWORD size,
    DWORD timeout);
/* Задание конфигурации цифровых входов и выходов крейта */
LTRAPIWIN_DllExport(INT) LTR_Config(TLTR *ltr, const TLTR_CONFIG *conf);
/* Включение внутренней генерации секундных меток */
LTRAPIWIN_DllExport(INT) LTR_StartSecondMark(TLTR *ltr, enum en_LTR_MarkMode mode);
/* Отключение внутренней генерации секундных меток */
LTRAPIWIN_DllExport(INT) LTR_StopSecondMark(TLTR *ltr);
/* Выбор режима генерации метки СТАРТ (или однократная вставка программной метки) */
LTRAPIWIN_DllExport(INT) LTR_MakeStartMark(TLTR *ltr, enum en_LTR_MarkMode mode);
/* Чтение приоритета процесса ltrserver.exe */
LTRAPIWIN_DllExport(INT) LTR_GetServerProcessPriority(TLTR *ltr, DWORD *Priority);
LTRAPIWIN_DllExport(INT) LTR_PutSettings(TLTR *h_ltr, const TLTR_SETTINGS *settings);

/* -- Функции управления сервером (работают по управляющему каналу,
 * -- в т.ч. без крейта через особый серийный номер CSN_SERVER_CONTROL)
 */
/* Чтение номера версии сервера (DWORD, 0x01020304 = 1.2.3.4) */
LTRAPIWIN_DllExport(INT) LTR_GetServerVersion(TLTR *ltr, DWORD *version);

/* Получение списка известных серверу IP-крейтов (подключенных и не подключенных)
 * Соответствует содержимому окна сервера "Управление IP-крейтами".
 */
LTRAPIWIN_DllExport(INT) LTR_GetListOfIPCrates(TLTR *ltr, DWORD max_entries, DWORD ip_net,
    DWORD ip_mask, DWORD *entries_found, DWORD *entries_returned, TLTR_CRATE_IP_ENTRY *info_array);

/* Добавление IP-адреса крейта в таблицу (с сохранением в файле конфигурации).
 * Если адрес уже существует, возвращает ошибку.
 */
LTRAPIWIN_DllExport(INT) LTR_AddIPCrate(TLTR *ltr, DWORD ip_addr, DWORD flags, BOOL permanent);

/* Удаление IP-адреса крейта из таблицы (и из файла конфигурации, если он статический).
 * Если адреса нет, либо крейт занят, возвращает ошибку.
 */
LTRAPIWIN_DllExport(INT) LTR_DeleteIPCrate(TLTR *ltr, DWORD ip_addr, BOOL permanent);

/* Установление соединения с IP-крейтом (адрес должен быть в таблице)
 * Если адреса нет, возвращает ошибку. Если крейт уже подключен или идет попытка подключения,
 * возвращает LTR_OK.
 * Если вернулось LTR_OK, это значит, что ОТПРАВЛЕНА КОМАНДА установить соединение.
 * Результат можно отследить позже по LTR_GetCrates() или LTR_GetListOfIPCrates()
 */
LTRAPIWIN_DllExport(INT) LTR_ConnectIPCrate(TLTR *ltr, DWORD ip_addr);

/* Завершение соединения с IP-крейтом (адрес должен быть в таблице)
 * Если адреса нет, возвращает ошибку. Если крейт уже отключен, возвращает LTR_OK.
 * Если вернулось LTR_OK, это значит, что ОТПРАВЛЕНА КОМАНДА завершить соединение.
 * Результат можно отследить позже по LTR_GetCrates() или LTR_GetListOfIPCrates()
 */
LTRAPIWIN_DllExport(INT) LTR_DisconnectIPCrate(TLTR *ltr, DWORD ip_addr);

/* Установление соединения со всеми IP-крейтами, имеющими флаг "автоподключение"
 * Если вернулось LTR_OK, это значит, что ОТПРАВЛЕНА КОМАНДА установить соединение.
 * Результат можно отследить позже по LTR_GetCrates() или LTR_GetListOfIPCrates()
 */
LTRAPIWIN_DllExport(INT) LTR_ConnectAllAutoIPCrates(TLTR *ltr);

/* Завершение соединения со всеми IP-крейтами
 * Если вернулось LTR_OK, это значит, что ОТПРАВЛЕНА КОМАНДА завершить соединение.
 * Результат можно отследить позже по LTR_GetCrates() или LTR_GetListOfIPCrates()
 */
LTRAPIWIN_DllExport(INT) LTR_DisconnectAllIPCrates(TLTR *ltr);

/* Изменение флагов для IP-крейта */
LTRAPIWIN_DllExport(INT) LTR_SetIPCrateFlags(TLTR *ltr, DWORD ip_addr, DWORD new_flags,
    BOOL permanent);

/* Чтение режима поиска IP-крейтов в локальной сети */
LTRAPIWIN_DllExport(INT) LTR_GetIPCrateDiscoveryMode(TLTR *ltr, BOOL *enabled, BOOL *autoconnect);

/* Установка режима поиска IP-крейтов в локальной сети */
LTRAPIWIN_DllExport(INT) LTR_SetIPCrateDiscoveryMode(TLTR *ltr, BOOL enabled, BOOL autoconnect,
    BOOL permanent);

/* Чтение уровня журнализации */
LTRAPIWIN_DllExport(INT) LTR_GetLogLevel(TLTR *ltr, INT *level);

/* Установка уровня журнализации */
LTRAPIWIN_DllExport(INT) LTR_SetLogLevel(TLTR *ltr, INT level, BOOL permanent);

/* Рестарт программы ltrserver (с разрывом всех соединений).
 * После успешного выполнения команды связь с сервером теряется.
 */
LTRAPIWIN_DllExport(INT) LTR_ServerRestart(TLTR *ltr);

/* Рестарт программы ltrserver (с разрывом всех соединений)
 * После успешного выполнения команды связь с сервером теряется.
 */
LTRAPIWIN_DllExport(INT) LTR_ServerShutdown(TLTR *ltr);

/* Установка таймаута по умолчанию для send/recv
 * Используется в LTR_Send и LTR_Recv, если задан таймаут 0,
 * а также во всех командах управляющего канала.
 */
LTRAPIWIN_DllExport(INT) LTR_SetTimeout(TLTR *ltr, DWORD ms);



LTRAPIWIN_DllExport(INT) LTR_CrateGetArray(TLTR *ltr, DWORD address, BYTE *buf, DWORD size);
LTRAPIWIN_DllExport(INT) LTR_CratePutArray(TLTR *ltr, DWORD address, const BYTE *buf, DWORD size);


/* получение статистики по крейту */
LTRAPIWIN_DllExport(INT) LTR_GetCrateStatistic(TLTR *ltr, INT iface, const char *serial,
    TLTR_CRATE_STATISTIC *stat, INT size);

/* получение статистики по модулю */
LTRAPIWIN_DllExport(INT) LTR_GetModuleStatistic(TLTR *ltr, INT iface, const char *serial, INT slot,
    TLTR_MODULE_STATISTIC *stat, INT size);

/* сброс модуля в указанном слоте */
LTRAPIWIN_DllExport(INT) LTR_ResetModule(TLTR *ltr, INT iface, const char *serial, INT slot,
    DWORD flags);

/* получение расширенного описания крейта */
LTRAPIWIN_DllExport(INT) LTR_GetCrateDescr(TLTR *ltr, INT iface, const char *serial,
    TLTR_CRATE_DESCR *stat, INT size);
/* установка параметра LTR-сервера */
LTRAPIWIN_DllExport(INT) LTR_SetServerParameter(TLTR *ltr, DWORD param, void *val, DWORD size);
/* получение значения параметра LTR-сервера */
LTRAPIWIN_DllExport(INT) LTR_GetServerParameter(TLTR *ltr, DWORD param, void *val, DWORD *size);

//получение списка серийных номеров крейтов с доп. информацией (можно больше 16)
LTRAPIWIN_DllExport(INT)    LTR_GetCratesWithInfo(TLTR *ltr, CHAR serials[][LTR_CRATE_SERIAL_SIZE],
                                                  TLTR_CRATE_INFO *info_list, DWORD max_size,
                                                  DWORD *crates_returned, DWORD *crates_found);

/* Передача произвольного запроса крейту */
LTRAPIWIN_DllExport(INT) LTR_CrateCustomCtlReq(TLTR *ltr, DWORD req, DWORD param,
    const BYTE *snd_buf, DWORD snd_size, BYTE *rcv_buf, DWORD rcv_size, DWORD *recvd_size);

LTRAPIWIN_DllExport(INT) LTR_RawRecv(TLTR *ltr, BYTE* buf, DWORD size, DWORD tout);

#ifdef __cplusplus
}
#endif

#endif /*#ifndef LTRAPI_H_*/
