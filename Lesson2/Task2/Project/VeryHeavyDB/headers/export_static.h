
#ifndef API_VERYHEAVYDB_H
#define API_VERYHEAVYDB_H

#ifdef VERYHEAVYDB_STATIC_DEFINE
#  define API_VERYHEAVYDB
#  define VERYHEAVYDB_NO_EXPORT
#else
#  ifndef API_VERYHEAVYDB
#    ifdef VeryHeavyDB_EXPORTS
        /* We are building this library */
#      define API_VERYHEAVYDB 
#    else
        /* We are using this library */
#      define API_VERYHEAVYDB 
#    endif
#  endif

#  ifndef VERYHEAVYDB_NO_EXPORT
#    define VERYHEAVYDB_NO_EXPORT 
#  endif
#endif

#ifndef VERYHEAVYDB_DEPRECATED
#  define VERYHEAVYDB_DEPRECATED __declspec(deprecated)
#endif

#ifndef VERYHEAVYDB_DEPRECATED_EXPORT
#  define VERYHEAVYDB_DEPRECATED_EXPORT API_VERYHEAVYDB VERYHEAVYDB_DEPRECATED
#endif

#ifndef VERYHEAVYDB_DEPRECATED_NO_EXPORT
#  define VERYHEAVYDB_DEPRECATED_NO_EXPORT VERYHEAVYDB_NO_EXPORT VERYHEAVYDB_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VERYHEAVYDB_NO_DEPRECATED
#    define VERYHEAVYDB_NO_DEPRECATED
#  endif
#endif

#endif /* API_VERYHEAVYDB_H */
