/*
 * Copyright (c) 2011 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. 
 */


#ifndef __TIZEN_COMMON_ERROR_H__
#define __TIZEN_COMMON_ERROR_H__

#include <errno.h>

/**
 * @defgroup CAPI_COMMON_ERROR Common Error Code
 * @brief This file provides error codes that are common for the whole TIZEN API.
 * @section CAPI_COMMON_ERROR_HEADER Required Header
 *   \#include <tizen_error.h>
 * @ingroup CAPI_BASE_FRAMEWORK
 * @{
 */

 

#define TIZEN_ERROR_MAX_PLATFORM_ERROR 0
#define TIZEN_ERROR_MIN_PLATFORM_ERROR (-1073741824LL) /* = -2147483648 / 2 */

/** Use this constant macro as the value of the first module specific error */
#define TIZEN_ERROR_MIN_MODULE_ERROR (-2147483648LL)

/** Module errors cannot be greater than the following constant */
#define TIZEN_ERROR_MAX_MODULE_ERROR (TIZEN_ERROR_MIN_PLATFORM_ERROR - 1)

/** Check if error or not */
#define TIZEN_ERROR_IS_OK(x) (0 <= (x))

/** Check if error or not */
#define TIZEN_ERROR_IS_ERROR(x) (!TIZEN_ERROR_IS_OK(x))

/** Check if slp error or not */
#define TIZEN_ERROR_IS_PLATFORM_ERROR(x) (TIZEN_ERROR_MIN_PLATFORM_ERROR <= (x) && (x) < 0)

/** Application Error Class */
#define TIZEN_ERROR_APPLICATION_CLASS -0x00000200
/** Base Error Class */
#define TIZEN_ERROR_BASE_CLASS -0x00000400
/** Content Error Class */
#define TIZEN_ERROR_CONTENT_CLASS -0x00000800
/** Location Error Class */
#define TIZEN_ERROR_LOCATION_CLASS -0x00001000
/** Multimedia Error Class */
#define TIZEN_ERROR_MULTIMEDIA_CLASS -0x00002000
/** Messaging Error Class */
#define TIZEN_ERROR_MESSAGING_CLASS -0x00004000
/** Network Error Class */
#define TIZEN_ERROR_NETWORK_CLASS -0x00008000
/** Social Error Class */
#define TIZEN_ERROR_SOCIAL_CLASS -0x00010000
/** System Error Class */
#define TIZEN_ERROR_SYSTEM_CLASS -0x00020000
/** Telephony Error Class */
#define TIZEN_ERROR_TELEPHONY_CLASS -0x00040000
/** UI Error class */
#define TIZEN_ERROR_UI_CLASS -0x00080000
/** UIX Error class */
#define TIZEN_ERROR_UIX_CLASS -0x00100000
/** AD Error class */
#define TIZEN_ERROR_AD_CLASS -0x00200000
/** Web Error class */
#define TIZEN_ERROR_WEB_CLASS -0x00400000

typedef enum
{
    TIZEN_ERROR_NONE = 0, /**< Successful */
    TIZEN_ERROR_NOT_PERMITTED = -EPERM, /**< Operation not permitted */
    TIZEN_ERROR_NO_SUCH_FILE = -ENOENT, /**< No such file or directory */
    TIZEN_ERROR_NO_SUCH_PROCESS = -ESRCH, /**< No such process */
    TIZEN_ERROR_INTERRUPTED_SYS_CALL = -EINTR, /**< Interrupted system call */
    TIZEN_ERROR_IO_ERROR = -EIO, /**< I/O error */
    TIZEN_ERROR_NO_SUCH_DEVICE = -ENXIO, /**< No such device or address */
    TIZEN_ERROR_ARGUMENT_LIST_TOO_LONG = -E2BIG, /**< Argument list too long */
    TIZEN_ERROR_EXEC_FORMAT_ERROR = -ENOEXEC, /**< Exec format error */
    TIZEN_ERROR_BAD_FILE_NUMBER = -EBADF, /**< Bad file number */

    TIZEN_ERROR_TRY_AGAIN = -EAGAIN, /**< Try again */
    TIZEN_ERROR_OUT_OF_MEMORY = -ENOMEM, /**< Out of memory */
    TIZEN_ERROR_PERMISSION_DENIED = -EACCES, /**< Permission denied */
    TIZEN_ERROR_BAD_ADDRESS = -EFAULT, /**< Bad address */
    TIZEN_ERROR_BLOCK_DEVICE_REQUIRED = -ENOTBLK, /**< Block device required */
    TIZEN_ERROR_RESOURCE_BUSY = -EBUSY, /**< Device or resource busy */
    TIZEN_ERROR_FILE_EXISTS = -EEXIST, /**< File exists */
    TIZEN_ERROR_CROSS_DEVICE_LINK = -EXDEV, /**< Cross-device link */
    TIZEN_ERROR_NOT_A_DIRECTORY = -ENOTDIR, /**< Not a directory */

    TIZEN_ERROR_IS_A_DIRECTORY = -EISDIR, /**< Is a directory */
    TIZEN_ERROR_INVALID_PARAMETER = -EINVAL, /**< Invalid function parameter */
    TIZEN_ERROR_FILE_TABLE_OVERFLOW = -ENFILE, /**< File table overflow */
    TIZEN_ERROR_TOO_MANY_OPEN_FILES = -EMFILE, /**< Too many open files */
    TIZEN_ERROR_TOO_NOT_A_TERMINAL = -ENOTTY, /**< Not a terminal */
    TIZEN_ERROR_TOO_TEXT_FILE_BUSY = -ETXTBSY, /**< Not a terminal */
    TIZEN_ERROR_FILE_TOO_LARGE = -EFBIG, /**< File too large */
    TIZEN_ERROR_FILE_NO_SPACE_ON_DEVICE = -ENOSPC, /**< No space left on device */
    TIZEN_ERROR_ILLEGAL_SEEK = -ESPIPE, /**< Illegal seek */
    TIZEN_ERROR_READ_ONLY_FILESYSTEM = -EROFS, /**< Read-only file system */

    TIZEN_ERROR_TOO_MANY_LINKS = -EMLINK, /**< Too many links */
    TIZEN_ERROR_BROKEN_PIPE = -EPIPE, /**< Broken pipe */
    TIZEN_ERROR_ARGUMENT_OUT_OF_DOMAIN = -EDOM, /**< Math argument out of domain of func */
    TIZEN_ERROR_RESULT_OUT_OF_RANGE = -ERANGE, /**< Math result not representable */
    TIZEN_ERROR_WOULD_CAUSE_DEADLOCK = -EDEADLK, /**< Resource deadlock would occur */
    TIZEN_ERROR_FILE_NAME_TOO_LONG = -ENAMETOOLONG,/**< File name too long */
    TIZEN_ERROR_FILE_NO_LOCKS_AVAILABLE = -ENOLCK, /**< No record locks available */
    TIZEN_ERROR_INVALID_OPERATION = -ENOSYS, /**< Function not implemented */
    TIZEN_ERROR_DIR_NOT_EMPTY = -ENOTEMPTY, /**< Directory not empty */
    TIZEN_ERROR_TOO_MANY_SYMBOLIC_LINKS = -ELOOP, /**< Too many symbolic links encountered */
    TIZEN_ERROR_WOULD_BLOCK = TIZEN_ERROR_TRY_AGAIN, /**< Operation would block */
    TIZEN_ERROR_CORRUPTED_SHARED_LIB = -ELIBBAD, /**< Accessing a corrupted shared library */
    TIZEN_ERROR_LIB_SECTION_CORRUPTED = -ELIBSCN, /**< .lib section in a.out corrupted */
    TIZEN_ERROR_LINK_TOO_MANY_SHARED_LIB = -ELIBMAX, /**< Attempting to link in too many shared libraries */
    TIZEN_ERROR_SHARED_LIB_EXEC = -ELIBEXEC, /**< Cannot exec a shared library directly */
    TIZEN_ERROR_ILLEGAL_BYTE_SEQ = -EILSEQ, /**< Illegal byte sequence */
    TIZEN_ERROR_SYSTEM_CALL_RESTART = -ERESTART, /**< Interrupted system call should be restarted */
    TIZEN_ERROR_STREAMS_PIPE = -ESTRPIPE, /**< Streams pipe error */
    TIZEN_ERROR_TOO_MANY_USERS = -EUSERS, /**< Too many users */
    TIZEN_ERROR_NON_SOCKET = -ENOTSOCK, /**< Socket operation on non-socket */
    TIZEN_ERROR_NO_DEST_ADDRESS = -EDESTADDRREQ, /**< Destination address required */
    TIZEN_ERROR_MSG_TOO_LONG = -EMSGSIZE, /**< Message too long */
    TIZEN_ERROR_PROTOCOL_WRONG_TYPE = -EPROTOTYPE, /**< Protocol wrong type for socket */
    TIZEN_ERROR_PROTOCOL_NOT_AVALIABLE = -ENOPROTOOPT, /**< Protocol not available */
    TIZEN_ERROR_PROTOCOL_NOT_SUPPORTED = -EPROTONOSUPPORT, /**< Protocol not supported */
    TIZEN_ERROR_SOCKET_TYPE_NOT_SUPPORTED = -ESOCKTNOSUPPORT, /**< Socket type not supported */
    TIZEN_ERROR_ENDPOINT_OPERATIN_NOT_SUPPORTED = -EOPNOTSUPP, /**< Operation not supported on transport endpoint */
    TIZEN_ERROR_PROTOCOL_FAMILY_NOT_SUPPORTED = -EPFNOSUPPORT, /**< Protocol family not supported */
    TIZEN_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED = -EAFNOSUPPORT, /**< Address family not supported by protocol */
    TIZEN_ERROR_ADDRES_IN_USE = -EADDRINUSE, /**< Address already in use */
    TIZEN_ERROR_CANNOT_ASSIGN_ADDRESS = -EADDRNOTAVAIL, /**< Cannot assign requested address */
    TIZEN_ERROR_NETWORK_DOWN = -ENETDOWN, /**< Network is down */
    TIZEN_ERROR_NETWORK_UNREACHABLE = -ENETUNREACH, /**< Network is unreachable */
    TIZEN_ERROR_NETWORK_RESET = -ENETRESET, /**< Network dropped connection because of reset */
    TIZEN_ERROR_CONNECTION_ABORTED = -ECONNABORTED, /**< Software caused connection abort */
    TIZEN_ERROR_CONNECTION_RESET_BY_PEER = -ECONNRESET, /**< Connection reset by peer */
    TIZEN_ERROR_BUFFER_SPACE = -ENOBUFS, /**< No buffer space available */
    TIZEN_ERROR_ENDPOINT_CONNECTED = -EISCONN, /**< Transport endpoint is already connected */
    TIZEN_ERROR_ENDPOINT_NOT_CONNECTED = -ENOTCONN, /**< Transport endpoint is not connected */
    TIZEN_ERROR_ENDPOINT_SHUTDOWN = -ESHUTDOWN, /**< Cannot send after transport endpoint shutdown */
    TIZEN_ERROR_TOO_MANY_REFERENCES = -ETOOMANYREFS, /**< Too many references: cannot splice */
    TIZEN_ERROR_CONNECTION_TIME_OUT = -ETIMEDOUT, /**< Connection timed out */
    TIZEN_ERROR_CONNECTION_REFUSED = -ECONNREFUSED, /**< Connection refused */
    TIZEN_ERROR_HOST_DOWN = -EHOSTDOWN, /**< Host is down */
    TIZEN_ERROR_NO_ROUTE_TO_HOST = -EHOSTUNREACH, /**< No route to host */
    TIZEN_ERROR_ALREADY_IN_PROGRESS = -EALREADY, /**< Operation already in progress */
    TIZEN_ERROR_NOW_IN_PROGRESS = -EINPROGRESS, /**< Operation now in progress */
    TIZEN_ERROR_STALE_NFS_FILE_HANDLE = -ESTALE, /**< Stale NFS file handle */
    TIZEN_ERROR_STRUCTURE_UNCLEAN = -EUCLEAN, /**< Structure needs cleaning */
    TIZEN_ERROR_NOT_XENIX_NAMED_TYPE_FILE = -ENOTNAM, /**< Not a XENIX named type file */
    TIZEN_ERROR_NO_XENIX_SEMAPHORES_AVAILABLE = -ENAVAIL, /**< No XENIX semaphores available */
    TIZEN_ERROR_IS_NAMED_TYPE_FILE = -EISNAM, /**< Is a named type file */
    TIZEN_ERROR_REMOTE_IO = -EREMOTEIO, /**< Remote I/O error */
    TIZEN_ERROR_QUOTA_EXCEEDED = -EDQUOT, /**< Quota exceeded */
    TIZEN_ERROR_NO_MEDIUM = -ENOMEDIUM, /**< No medium found */
    TIZEN_ERROR_WRONG_MEDIUM_TYPE = -EMEDIUMTYPE, /**< Wrong medium type */
    TIZEN_ERROR_CANCELED = -ECANCELED, /**< Operation Canceled */
    TIZEN_ERROR_KEY_NOT_AVAILABLE = -ENOKEY, /**< Required key not available */
    TIZEN_ERROR_KEY_EXPIRED = -EKEYEXPIRED, /**< Key has expired */
    TIZEN_ERROR_KEY_REVOKED = -EKEYREVOKED, /**< Key has been revoked */
    TIZEN_ERROR_KEY_REJECTED = -EKEYREJECTED, /**< Key was rejected by service */

    TIZEN_ERROR_OWNER_DEAD = -EOWNERDEAD, /**< Owner died (for robust mutexes) */

    /** Different errors (not an errno) */
    TIZEN_ERROR_UNKNOWN = TIZEN_ERROR_MIN_PLATFORM_ERROR,

    /* This is a place to add new errors here.
     * Do not assign integer values explicitly. Values are auto-assigned.
     */
    TIZEN_ERROR_TIMED_OUT,
    TIZEN_ERROR_NOT_SUPPORT_API,
    TIZEN_ERROR_END_OF_COLLECTION,

} tizen_error_e;

/**
 * @}
 */

#endif         /**<__TIZEN_COMMON_ERROR_H__ */
