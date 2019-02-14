/**
 * Orthanc - A Lightweight, RESTful DICOM Store
 * Copyright (C) 2012-2016 Sebastien Jodogne, Medical Physics
 * Department, University Hospital of Liege, Belgium
 * Copyright (C) 2017-2019 Osimis S.A., Belgium
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * In addition, as a special exception, the copyright holders of this
 * program give permission to link the code of its release with the
 * OpenSSL project's "OpenSSL" library (or with modified versions of it
 * that use the same license as the "OpenSSL" library), and distribute
 * the linked executables. You must obey the GNU General Public License
 * in all respects for all of the code used other than "OpenSSL". If you
 * modify file(s) with this exception, you may extend this exception to
 * your version of the file(s), but you are not obligated to do so. If
 * you do not wish to do so, delete this exception statement from your
 * version. If you delete this exception statement from all source files
 * in the program, then also delete it here.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 **/


#pragma once

#include <string>


// Macro "ORTHANC_FORCE_INLINE" forces a function/method to be inlined
#if defined(_MSC_VER)
#  define ORTHANC_FORCE_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__) || defined(__EMSCRIPTEN__)
#  define ORTHANC_FORCE_INLINE inline __attribute((always_inline))
#else
#  error Please support your compiler here
#endif


// Macros "ORTHANC_OVERRIDE" and "ORTHANC_FINAL" wrap the "override"
// and "final" keywords introduced in C++11, to do compile-time
// checking of virtual methods
#if __cplusplus >= 201103L
// C++11 is enabled
#  define ORTHANC_OVERRIDE  override
#  define ORTHANC_FINAL     final
#else
// C++11 is disabled
#  define ORTHANC_OVERRIDE
#  define ORTHANC_FINAL
#endif


namespace Orthanc
{
  static const char* const URI_SCHEME_PREFIX_BINARY = "data:application/octet-stream;base64,";

  static const char* const MIME_BINARY = "application/octet-stream";
  static const char* const MIME_JPEG = "image/jpeg";
  static const char* const MIME_JSON = "application/json";
  static const char* const MIME_JSON_UTF8 = "application/json; charset=utf-8";
  static const char* const MIME_PDF = "application/pdf";
  static const char* const MIME_PNG = "image/png";
  static const char* const MIME_XML = "application/xml";
  static const char* const MIME_XML_UTF8 = "application/xml; charset=utf-8";

  /**
   * "No Internet Media Type (aka MIME type, content type) for PBM has
   * been registered with IANA, but the unofficial value
   * image/x-portable-arbitrarymap is assigned by this specification,
   * to be consistent with conventional values for the older Netpbm
   * formats."  http://netpbm.sourceforge.net/doc/pam.html
   **/
  static const char* const MIME_PAM = "image/x-portable-arbitrarymap";


  enum MimeType
  {
    MimeType_Binary,
    MimeType_Css,
    MimeType_Dicom,
    MimeType_Gif,
    MimeType_Gzip,
    MimeType_Html,
    MimeType_JavaScript,
    MimeType_Jpeg,
    MimeType_Jpeg2000,
    MimeType_Json,
    MimeType_NaCl,
    MimeType_PNaCl,
    MimeType_Pam,
    MimeType_Pdf,
    MimeType_PlainText,
    MimeType_Png,
    MimeType_Svg,
    MimeType_WebAssembly,
    MimeType_Xml,
    MimeType_Woff,            // Web Open Font Format
    MimeType_Zip,
    MimeType_PrometheusText,  // Prometheus text-based exposition format (for metrics)
    MimeType_DicomWebJson,
    MimeType_DicomWebXml
  };

  
  enum Endianness
  {
    Endianness_Unknown,
    Endianness_Big,
    Endianness_Little
  };

  // This enumeration is autogenerated by the script
  // "Resources/GenerateErrorCodes.py"
  enum ErrorCode
  {
    ErrorCode_InternalError = -1    /*!< Internal error */,
    ErrorCode_Success = 0    /*!< Success */,
    ErrorCode_Plugin = 1    /*!< Error encountered within the plugin engine */,
    ErrorCode_NotImplemented = 2    /*!< Not implemented yet */,
    ErrorCode_ParameterOutOfRange = 3    /*!< Parameter out of range */,
    ErrorCode_NotEnoughMemory = 4    /*!< The server hosting Orthanc is running out of memory */,
    ErrorCode_BadParameterType = 5    /*!< Bad type for a parameter */,
    ErrorCode_BadSequenceOfCalls = 6    /*!< Bad sequence of calls */,
    ErrorCode_InexistentItem = 7    /*!< Accessing an inexistent item */,
    ErrorCode_BadRequest = 8    /*!< Bad request */,
    ErrorCode_NetworkProtocol = 9    /*!< Error in the network protocol */,
    ErrorCode_SystemCommand = 10    /*!< Error while calling a system command */,
    ErrorCode_Database = 11    /*!< Error with the database engine */,
    ErrorCode_UriSyntax = 12    /*!< Badly formatted URI */,
    ErrorCode_InexistentFile = 13    /*!< Inexistent file */,
    ErrorCode_CannotWriteFile = 14    /*!< Cannot write to file */,
    ErrorCode_BadFileFormat = 15    /*!< Bad file format */,
    ErrorCode_Timeout = 16    /*!< Timeout */,
    ErrorCode_UnknownResource = 17    /*!< Unknown resource */,
    ErrorCode_IncompatibleDatabaseVersion = 18    /*!< Incompatible version of the database */,
    ErrorCode_FullStorage = 19    /*!< The file storage is full */,
    ErrorCode_CorruptedFile = 20    /*!< Corrupted file (e.g. inconsistent MD5 hash) */,
    ErrorCode_InexistentTag = 21    /*!< Inexistent tag */,
    ErrorCode_ReadOnly = 22    /*!< Cannot modify a read-only data structure */,
    ErrorCode_IncompatibleImageFormat = 23    /*!< Incompatible format of the images */,
    ErrorCode_IncompatibleImageSize = 24    /*!< Incompatible size of the images */,
    ErrorCode_SharedLibrary = 25    /*!< Error while using a shared library (plugin) */,
    ErrorCode_UnknownPluginService = 26    /*!< Plugin invoking an unknown service */,
    ErrorCode_UnknownDicomTag = 27    /*!< Unknown DICOM tag */,
    ErrorCode_BadJson = 28    /*!< Cannot parse a JSON document */,
    ErrorCode_Unauthorized = 29    /*!< Bad credentials were provided to an HTTP request */,
    ErrorCode_BadFont = 30    /*!< Badly formatted font file */,
    ErrorCode_DatabasePlugin = 31    /*!< The plugin implementing a custom database back-end does not fulfill the proper interface */,
    ErrorCode_StorageAreaPlugin = 32    /*!< Error in the plugin implementing a custom storage area */,
    ErrorCode_EmptyRequest = 33    /*!< The request is empty */,
    ErrorCode_NotAcceptable = 34    /*!< Cannot send a response which is acceptable according to the Accept HTTP header */,
    ErrorCode_NullPointer = 35    /*!< Cannot handle a NULL pointer */,
    ErrorCode_DatabaseUnavailable = 36    /*!< The database is currently not available (probably a transient situation) */,
    ErrorCode_CanceledJob = 37    /*!< This job was canceled */,
    ErrorCode_SQLiteNotOpened = 1000    /*!< SQLite: The database is not opened */,
    ErrorCode_SQLiteAlreadyOpened = 1001    /*!< SQLite: Connection is already open */,
    ErrorCode_SQLiteCannotOpen = 1002    /*!< SQLite: Unable to open the database */,
    ErrorCode_SQLiteStatementAlreadyUsed = 1003    /*!< SQLite: This cached statement is already being referred to */,
    ErrorCode_SQLiteExecute = 1004    /*!< SQLite: Cannot execute a command */,
    ErrorCode_SQLiteRollbackWithoutTransaction = 1005    /*!< SQLite: Rolling back a nonexistent transaction (have you called Begin()?) */,
    ErrorCode_SQLiteCommitWithoutTransaction = 1006    /*!< SQLite: Committing a nonexistent transaction */,
    ErrorCode_SQLiteRegisterFunction = 1007    /*!< SQLite: Unable to register a function */,
    ErrorCode_SQLiteFlush = 1008    /*!< SQLite: Unable to flush the database */,
    ErrorCode_SQLiteCannotRun = 1009    /*!< SQLite: Cannot run a cached statement */,
    ErrorCode_SQLiteCannotStep = 1010    /*!< SQLite: Cannot step over a cached statement */,
    ErrorCode_SQLiteBindOutOfRange = 1011    /*!< SQLite: Bing a value while out of range (serious error) */,
    ErrorCode_SQLitePrepareStatement = 1012    /*!< SQLite: Cannot prepare a cached statement */,
    ErrorCode_SQLiteTransactionAlreadyStarted = 1013    /*!< SQLite: Beginning the same transaction twice */,
    ErrorCode_SQLiteTransactionCommit = 1014    /*!< SQLite: Failure when committing the transaction */,
    ErrorCode_SQLiteTransactionBegin = 1015    /*!< SQLite: Cannot start a transaction */,
    ErrorCode_DirectoryOverFile = 2000    /*!< The directory to be created is already occupied by a regular file */,
    ErrorCode_FileStorageCannotWrite = 2001    /*!< Unable to create a subdirectory or a file in the file storage */,
    ErrorCode_DirectoryExpected = 2002    /*!< The specified path does not point to a directory */,
    ErrorCode_HttpPortInUse = 2003    /*!< The TCP port of the HTTP server is privileged or already in use */,
    ErrorCode_DicomPortInUse = 2004    /*!< The TCP port of the DICOM server is privileged or already in use */,
    ErrorCode_BadHttpStatusInRest = 2005    /*!< This HTTP status is not allowed in a REST API */,
    ErrorCode_RegularFileExpected = 2006    /*!< The specified path does not point to a regular file */,
    ErrorCode_PathToExecutable = 2007    /*!< Unable to get the path to the executable */,
    ErrorCode_MakeDirectory = 2008    /*!< Cannot create a directory */,
    ErrorCode_BadApplicationEntityTitle = 2009    /*!< An application entity title (AET) cannot be empty or be longer than 16 characters */,
    ErrorCode_NoCFindHandler = 2010    /*!< No request handler factory for DICOM C-FIND SCP */,
    ErrorCode_NoCMoveHandler = 2011    /*!< No request handler factory for DICOM C-MOVE SCP */,
    ErrorCode_NoCStoreHandler = 2012    /*!< No request handler factory for DICOM C-STORE SCP */,
    ErrorCode_NoApplicationEntityFilter = 2013    /*!< No application entity filter */,
    ErrorCode_NoSopClassOrInstance = 2014    /*!< DicomUserConnection: Unable to find the SOP class and instance */,
    ErrorCode_NoPresentationContext = 2015    /*!< DicomUserConnection: No acceptable presentation context for modality */,
    ErrorCode_DicomFindUnavailable = 2016    /*!< DicomUserConnection: The C-FIND command is not supported by the remote SCP */,
    ErrorCode_DicomMoveUnavailable = 2017    /*!< DicomUserConnection: The C-MOVE command is not supported by the remote SCP */,
    ErrorCode_CannotStoreInstance = 2018    /*!< Cannot store an instance */,
    ErrorCode_CreateDicomNotString = 2019    /*!< Only string values are supported when creating DICOM instances */,
    ErrorCode_CreateDicomOverrideTag = 2020    /*!< Trying to override a value inherited from a parent module */,
    ErrorCode_CreateDicomUseContent = 2021    /*!< Use \"Content\" to inject an image into a new DICOM instance */,
    ErrorCode_CreateDicomNoPayload = 2022    /*!< No payload is present for one instance in the series */,
    ErrorCode_CreateDicomUseDataUriScheme = 2023    /*!< The payload of the DICOM instance must be specified according to Data URI scheme */,
    ErrorCode_CreateDicomBadParent = 2024    /*!< Trying to attach a new DICOM instance to an inexistent resource */,
    ErrorCode_CreateDicomParentIsInstance = 2025    /*!< Trying to attach a new DICOM instance to an instance (must be a series, study or patient) */,
    ErrorCode_CreateDicomParentEncoding = 2026    /*!< Unable to get the encoding of the parent resource */,
    ErrorCode_UnknownModality = 2027    /*!< Unknown modality */,
    ErrorCode_BadJobOrdering = 2028    /*!< Bad ordering of filters in a job */,
    ErrorCode_JsonToLuaTable = 2029    /*!< Cannot convert the given JSON object to a Lua table */,
    ErrorCode_CannotCreateLua = 2030    /*!< Cannot create the Lua context */,
    ErrorCode_CannotExecuteLua = 2031    /*!< Cannot execute a Lua command */,
    ErrorCode_LuaAlreadyExecuted = 2032    /*!< Arguments cannot be pushed after the Lua function is executed */,
    ErrorCode_LuaBadOutput = 2033    /*!< The Lua function does not give the expected number of outputs */,
    ErrorCode_NotLuaPredicate = 2034    /*!< The Lua function is not a predicate (only true/false outputs allowed) */,
    ErrorCode_LuaReturnsNoString = 2035    /*!< The Lua function does not return a string */,
    ErrorCode_StorageAreaAlreadyRegistered = 2036    /*!< Another plugin has already registered a custom storage area */,
    ErrorCode_DatabaseBackendAlreadyRegistered = 2037    /*!< Another plugin has already registered a custom database back-end */,
    ErrorCode_DatabaseNotInitialized = 2038    /*!< Plugin trying to call the database during its initialization */,
    ErrorCode_SslDisabled = 2039    /*!< Orthanc has been built without SSL support */,
    ErrorCode_CannotOrderSlices = 2040    /*!< Unable to order the slices of the series */,
    ErrorCode_NoWorklistHandler = 2041    /*!< No request handler factory for DICOM C-Find Modality SCP */,
    ErrorCode_AlreadyExistingTag = 2042    /*!< Cannot override the value of a tag that already exists */,
    ErrorCode_START_PLUGINS = 1000000
  };

  enum LogLevel
  {
    LogLevel_Error,
    LogLevel_Warning,
    LogLevel_Info,
    LogLevel_Trace
  };


  /**
   * {summary}{The memory layout of the pixels (resp. voxels) of a 2D (resp. 3D) image.}
   **/
  enum PixelFormat
  {
    /**
     * {summary}{Color image in RGB24 format.}
     * {description}{This format describes a color image. The pixels are stored in 3
     * consecutive bytes. The memory layout is RGB.}
     **/
    PixelFormat_RGB24 = 1,

    /**
     * {summary}{Color image in RGBA32 format.}
     * {description}{This format describes a color image. The pixels are stored in 4
     * consecutive bytes. The memory layout is RGBA.}
     **/
    PixelFormat_RGBA32 = 2,

    /**
     * {summary}{Graylevel 8bpp image.}
     * {description}{The image is graylevel. Each pixel is unsigned and stored in one byte.}
     **/
    PixelFormat_Grayscale8 = 3,
      
    /**
     * {summary}{Graylevel, unsigned 16bpp image.}
     * {description}{The image is graylevel. Each pixel is unsigned and stored in two bytes.}
     **/
    PixelFormat_Grayscale16 = 4,
      
    /**
     * {summary}{Graylevel, signed 16bpp image.}
     * {description}{The image is graylevel. Each pixel is signed and stored in two bytes.}
     **/
    PixelFormat_SignedGrayscale16 = 5,
      
    /**
     * {summary}{Graylevel, floating-point image.}
     * {description}{The image is graylevel. Each pixel is floating-point and stored in 4 bytes.}
     **/
    PixelFormat_Float32 = 6,

    // This is the memory layout for Cairo (for internal use in Stone of Orthanc)
    PixelFormat_BGRA32 = 7,

    /**
     * {summary}{Graylevel, unsigned 32bpp image.}
     * {description}{The image is graylevel. Each pixel is unsigned and stored in 4 bytes.}
     **/
    PixelFormat_Grayscale32 = 8,
    
    /**
     * {summary}{Color image in RGB48 format.}
     * {description}{This format describes a color image. The pixels are stored in 6
     * consecutive bytes. The memory layout is RGB.}
     **/
    PixelFormat_RGB48 = 9,

    /**
     * {summary}{Graylevel, unsigned 64bpp image.}
     * {description}{The image is graylevel. Each pixel is unsigned and stored in 4 bytes.}
     **/
    PixelFormat_Grayscale64 = 10
  };


  /**
   * {summary}{The extraction mode specifies the way the values of the pixels are scaled when downloading a 2D image.}
   **/
  enum ImageExtractionMode
  {
    /**
     * {summary}{Rescaled to 8bpp.}
     * {description}{The minimum value of the image is set to 0, and its maximum value is set to 255.}
     **/
    ImageExtractionMode_Preview = 1,

    /**
     * {summary}{Truncation to the [0, 255] range.}
     **/
    ImageExtractionMode_UInt8 = 2,

    /**
     * {summary}{Truncation to the [0, 65535] range.}
     **/
    ImageExtractionMode_UInt16 = 3,

    /**
     * {summary}{Truncation to the [-32768, 32767] range.}
     **/
    ImageExtractionMode_Int16 = 4
  };


  /**
   * Most common, non-joke and non-experimental HTTP status codes
   * http://en.wikipedia.org/wiki/List_of_HTTP_status_codes
   **/
  enum HttpStatus
  {
    HttpStatus_None = -1,

    // 1xx Informational
    HttpStatus_100_Continue = 100,
    HttpStatus_101_SwitchingProtocols = 101,
    HttpStatus_102_Processing = 102,

    // 2xx Success
    HttpStatus_200_Ok = 200,
    HttpStatus_201_Created = 201,
    HttpStatus_202_Accepted = 202,
    HttpStatus_203_NonAuthoritativeInformation = 203,
    HttpStatus_204_NoContent = 204,
    HttpStatus_205_ResetContent = 205,
    HttpStatus_206_PartialContent = 206,
    HttpStatus_207_MultiStatus = 207,
    HttpStatus_208_AlreadyReported = 208,
    HttpStatus_226_IMUsed = 226,

    // 3xx Redirection
    HttpStatus_300_MultipleChoices = 300,
    HttpStatus_301_MovedPermanently = 301,
    HttpStatus_302_Found = 302,
    HttpStatus_303_SeeOther = 303,
    HttpStatus_304_NotModified = 304,
    HttpStatus_305_UseProxy = 305,
    HttpStatus_307_TemporaryRedirect = 307,

    // 4xx Client Error
    HttpStatus_400_BadRequest = 400,
    HttpStatus_401_Unauthorized = 401,
    HttpStatus_402_PaymentRequired = 402,
    HttpStatus_403_Forbidden = 403,
    HttpStatus_404_NotFound = 404,
    HttpStatus_405_MethodNotAllowed = 405,
    HttpStatus_406_NotAcceptable = 406,
    HttpStatus_407_ProxyAuthenticationRequired = 407,
    HttpStatus_408_RequestTimeout = 408,
    HttpStatus_409_Conflict = 409,
    HttpStatus_410_Gone = 410,
    HttpStatus_411_LengthRequired = 411,
    HttpStatus_412_PreconditionFailed = 412,
    HttpStatus_413_RequestEntityTooLarge = 413,
    HttpStatus_414_RequestUriTooLong = 414,
    HttpStatus_415_UnsupportedMediaType = 415,
    HttpStatus_416_RequestedRangeNotSatisfiable = 416,
    HttpStatus_417_ExpectationFailed = 417,
    HttpStatus_422_UnprocessableEntity = 422,
    HttpStatus_423_Locked = 423,
    HttpStatus_424_FailedDependency = 424,
    HttpStatus_426_UpgradeRequired = 426,

    // 5xx Server Error
    HttpStatus_500_InternalServerError = 500,
    HttpStatus_501_NotImplemented = 501,
    HttpStatus_502_BadGateway = 502,
    HttpStatus_503_ServiceUnavailable = 503,
    HttpStatus_504_GatewayTimeout = 504,
    HttpStatus_505_HttpVersionNotSupported = 505,
    HttpStatus_506_VariantAlsoNegotiates = 506,
    HttpStatus_507_InsufficientStorage = 507,
    HttpStatus_509_BandwidthLimitExceeded = 509,
    HttpStatus_510_NotExtended = 510
  };


  enum HttpMethod
  {
    HttpMethod_Get = 0,
    HttpMethod_Post = 1,
    HttpMethod_Delete = 2,
    HttpMethod_Put = 3
  };


  enum ImageFormat
  {
    ImageFormat_Png = 1
  };


  // https://en.wikipedia.org/wiki/HTTP_compression
  enum HttpCompression
  {
    HttpCompression_None,
    HttpCompression_Deflate,
    HttpCompression_Gzip
  };


  // Specific Character Sets
  // http://dicom.nema.org/medical/dicom/current/output/html/part03.html#sect_C.12.1.1.2
  enum Encoding
  {
    Encoding_Ascii,
    Encoding_Utf8,
    Encoding_Latin1,
    Encoding_Latin2,
    Encoding_Latin3,
    Encoding_Latin4,
    Encoding_Latin5,                        // Turkish
    Encoding_Cyrillic,
    Encoding_Windows1251,                   // Windows-1251 (commonly used for Cyrillic)
    Encoding_Arabic,
    Encoding_Greek,
    Encoding_Hebrew,
    Encoding_Thai,                          // TIS 620-2533
    Encoding_Japanese,                      // JIS X 0201 (Shift JIS): Katakana
    Encoding_Chinese,                       // GB18030 - Chinese simplified
    Encoding_JapaneseKanji,                 // Multibyte - JIS X 0208: Kanji
    //Encoding_JapaneseSupplementaryKanji,  // Multibyte - JIS X 0212: Supplementary Kanji set
    Encoding_Korean,                        // Multibyte - KS X 1001: Hangul and Hanja
    Encoding_SimplifiedChinese              // ISO 2022 IR 58
  };


  // http://dicom.nema.org/medical/dicom/current/output/html/part03.html#sect_C.7.6.3.1.2
  enum PhotometricInterpretation
  {
    PhotometricInterpretation_ARGB,  // Retired
    PhotometricInterpretation_CMYK,  // Retired
    PhotometricInterpretation_HSV,   // Retired
    PhotometricInterpretation_Monochrome1,
    PhotometricInterpretation_Monochrome2,
    PhotometricInterpretation_Palette,
    PhotometricInterpretation_RGB,
    PhotometricInterpretation_YBRFull,
    PhotometricInterpretation_YBRFull422,
    PhotometricInterpretation_YBRPartial420,
    PhotometricInterpretation_YBRPartial422,
    PhotometricInterpretation_YBR_ICT,
    PhotometricInterpretation_YBR_RCT,
    PhotometricInterpretation_Unknown
  };

  enum DicomModule
  {
    DicomModule_Patient,
    DicomModule_Study,
    DicomModule_Series,
    DicomModule_Instance,
    DicomModule_Image
  };

  enum RequestOrigin
  {
    RequestOrigin_Unknown,
    RequestOrigin_DicomProtocol,
    RequestOrigin_RestApi,
    RequestOrigin_Plugins,
    RequestOrigin_Lua
  };

  enum ServerBarrierEvent
  {
    ServerBarrierEvent_Stop,
    ServerBarrierEvent_Reload  // SIGHUP signal: reload configuration file
  };

  enum FileMode
  {
    FileMode_ReadBinary,
    FileMode_WriteBinary
  };

  /**
   * The value representations Orthanc knows about. They correspond to
   * the DICOM 2016b version of the standard.
   * http://dicom.nema.org/medical/dicom/current/output/chtml/part05/sect_6.2.html
   **/
  enum ValueRepresentation
  {
    ValueRepresentation_ApplicationEntity = 1,     // AE
    ValueRepresentation_AgeString = 2,             // AS
    ValueRepresentation_AttributeTag = 3,          // AT (2 x uint16_t)
    ValueRepresentation_CodeString = 4,            // CS
    ValueRepresentation_Date = 5,                  // DA
    ValueRepresentation_DecimalString = 6,         // DS
    ValueRepresentation_DateTime = 7,              // DT
    ValueRepresentation_FloatingPointSingle = 8,   // FL (float)
    ValueRepresentation_FloatingPointDouble = 9,   // FD (double)
    ValueRepresentation_IntegerString = 10,        // IS
    ValueRepresentation_LongString = 11,           // LO
    ValueRepresentation_LongText = 12,             // LT
    ValueRepresentation_OtherByte = 13,            // OB
    ValueRepresentation_OtherDouble = 14,          // OD
    ValueRepresentation_OtherFloat = 15,           // OF
    ValueRepresentation_OtherLong = 16,            // OL
    ValueRepresentation_OtherWord = 17,            // OW
    ValueRepresentation_PersonName = 18,           // PN
    ValueRepresentation_ShortString = 19,          // SH
    ValueRepresentation_SignedLong = 20,           // SL (int32_t)
    ValueRepresentation_Sequence = 21,             // SQ
    ValueRepresentation_SignedShort = 22,          // SS (int16_t)
    ValueRepresentation_ShortText = 23,            // ST
    ValueRepresentation_Time = 24,                 // TM
    ValueRepresentation_UnlimitedCharacters = 25,  // UC
    ValueRepresentation_UniqueIdentifier = 26,     // UI (UID)
    ValueRepresentation_UnsignedLong = 27,         // UL (uint32_t)
    ValueRepresentation_Unknown = 28,              // UN
    ValueRepresentation_UniversalResource = 29,    // UR (URI or URL)
    ValueRepresentation_UnsignedShort = 30,        // US (uint16_t)
    ValueRepresentation_UnlimitedText = 31,        // UT
    ValueRepresentation_NotSupported               // Not supported by Orthanc, or tag not in dictionary
  };

  enum DicomReplaceMode
  {
    DicomReplaceMode_InsertIfAbsent,
    DicomReplaceMode_ThrowIfAbsent,
    DicomReplaceMode_IgnoreIfAbsent
  };

  enum DicomToJsonFormat
  {
    DicomToJsonFormat_Full,
    DicomToJsonFormat_Short,
    DicomToJsonFormat_Human
  };

  enum DicomToJsonFlags
  {
    DicomToJsonFlags_IncludeBinary         = (1 << 0),
    DicomToJsonFlags_IncludePrivateTags    = (1 << 1),
    DicomToJsonFlags_IncludeUnknownTags    = (1 << 2),
    DicomToJsonFlags_IncludePixelData      = (1 << 3),
    DicomToJsonFlags_ConvertBinaryToAscii  = (1 << 4),
    DicomToJsonFlags_ConvertBinaryToNull   = (1 << 5),

    // Some predefined combinations
    DicomToJsonFlags_None     = 0,
    DicomToJsonFlags_Default  = (DicomToJsonFlags_IncludeBinary |
                                 DicomToJsonFlags_IncludePixelData | 
                                 DicomToJsonFlags_IncludePrivateTags | 
                                 DicomToJsonFlags_IncludeUnknownTags | 
                                 DicomToJsonFlags_ConvertBinaryToNull)
  };
  
  enum DicomFromJsonFlags
  {
    DicomFromJsonFlags_DecodeDataUriScheme = (1 << 0),
    DicomFromJsonFlags_GenerateIdentifiers = (1 << 1),

    // Some predefined combinations
    DicomFromJsonFlags_None = 0
  };
  
  enum DicomVersion
  {
    DicomVersion_2008,
    DicomVersion_2017c
  };

  enum ModalityManufacturer
  {
    ModalityManufacturer_Generic,
    ModalityManufacturer_GenericNoWildcardInDates,
    ModalityManufacturer_GenericNoUniversalWildcard,
    ModalityManufacturer_StoreScp,
    ModalityManufacturer_ClearCanvas,
    ModalityManufacturer_Dcm4Chee,
    ModalityManufacturer_Vitrea,
    ModalityManufacturer_GE
  };

  enum DicomRequestType
  {
    DicomRequestType_Echo,
    DicomRequestType_Find,
    DicomRequestType_Get,
    DicomRequestType_Move,
    DicomRequestType_Store
  };

  enum TransferSyntax
  {
    TransferSyntax_Deflated,
    TransferSyntax_Jpeg,
    TransferSyntax_Jpeg2000,
    TransferSyntax_JpegLossless,
    TransferSyntax_Jpip,
    TransferSyntax_Mpeg2,
    TransferSyntax_Rle
  };

  enum JobState
  {
    JobState_Pending,
    JobState_Running,
    JobState_Success,
    JobState_Failure,
    JobState_Paused,
    JobState_Retry
  };

  enum JobStepCode
  {
    JobStepCode_Success,
    JobStepCode_Failure,
    JobStepCode_Continue,
    JobStepCode_Retry
  };

  enum JobStopReason
  {
    JobStopReason_Paused,
    JobStopReason_Canceled,
    JobStopReason_Success,
    JobStopReason_Failure,
    JobStopReason_Retry
  };


  /**
   * WARNING: Do not change the explicit values in the enumerations
   * below this point. This would result in incompatible databases
   * between versions of Orthanc!
   **/

  enum CompressionType
  {
    /**
     * Buffer/file that is stored as-is, in a raw fashion, without
     * compression.
     **/
    CompressionType_None = 1,

    /**
     * Buffer that is compressed using the "deflate" algorithm (RFC
     * 1951), wrapped inside the zlib data format (RFC 1950), prefixed
     * with a "uint64_t" (8 bytes) that encodes the size of the
     * uncompressed buffer. If the compressed buffer is empty, its
     * represents an empty uncompressed buffer. This format is
     * internal to Orthanc. If the 8 first bytes are skipped AND the
     * buffer is non-empty, the buffer is compatible with the
     * "deflate" HTTP compression.
     **/
    CompressionType_ZlibWithSize = 2
  };

  enum FileContentType
  {
    // If you add a value below, insert it in "PluginStorageArea" in
    // the file "Plugins/Engine/OrthancPlugins.cpp"
    FileContentType_Unknown = 0,
    FileContentType_Dicom = 1,
    FileContentType_DicomAsJson = 2,

    // Make sure that the value "65535" can be stored into this enumeration
    FileContentType_StartUser = 1024,
    FileContentType_EndUser = 65535
  };

  enum ResourceType
  {
    ResourceType_Patient = 1,
    ResourceType_Study = 2,
    ResourceType_Series = 3,
    ResourceType_Instance = 4
  };


  const char* EnumerationToString(ErrorCode code);

  const char* EnumerationToString(HttpMethod method);

  const char* EnumerationToString(HttpStatus status);

  const char* EnumerationToString(ResourceType type);

  const char* EnumerationToString(ImageFormat format);

  const char* EnumerationToString(Encoding encoding);

  const char* EnumerationToString(PhotometricInterpretation photometric);

  const char* EnumerationToString(LogLevel level);

  const char* EnumerationToString(RequestOrigin origin);

  const char* EnumerationToString(PixelFormat format);

  const char* EnumerationToString(ModalityManufacturer manufacturer);

  const char* EnumerationToString(DicomRequestType type);

  const char* EnumerationToString(TransferSyntax syntax);

  const char* EnumerationToString(DicomVersion version);

  const char* EnumerationToString(ValueRepresentation vr);

  const char* EnumerationToString(JobState state);

  const char* EnumerationToString(MimeType mime);

  Encoding StringToEncoding(const char* encoding);

  ResourceType StringToResourceType(const char* type);

  ImageFormat StringToImageFormat(const char* format);

  LogLevel StringToLogLevel(const char* level);

  ValueRepresentation StringToValueRepresentation(const std::string& vr,
                                                  bool throwIfUnsupported);

  PhotometricInterpretation StringToPhotometricInterpretation(const char* value);

  ModalityManufacturer StringToModalityManufacturer(const std::string& manufacturer);

  DicomVersion StringToDicomVersion(const std::string& version);

  JobState StringToJobState(const std::string& state);
  
  RequestOrigin StringToRequestOrigin(const std::string& origin);

  MimeType StringToMimeType(const std::string& mime);
  
  unsigned int GetBytesPerPixel(PixelFormat format);

  bool GetDicomEncoding(Encoding& encoding,
                        const char* specificCharacterSet);

  ResourceType GetChildResourceType(ResourceType type);

  ResourceType GetParentResourceType(ResourceType type);

  bool IsResourceLevelAboveOrEqual(ResourceType level,
                                   ResourceType reference);

  DicomModule GetModule(ResourceType type);

  const char* GetDicomSpecificCharacterSet(Encoding encoding);

  HttpStatus ConvertErrorCodeToHttpStatus(ErrorCode error);

  bool IsUserContentType(FileContentType type);

  bool IsBinaryValueRepresentation(ValueRepresentation vr);
  
  Encoding GetDefaultDicomEncoding();

  void SetDefaultDicomEncoding(Encoding encoding);
}
