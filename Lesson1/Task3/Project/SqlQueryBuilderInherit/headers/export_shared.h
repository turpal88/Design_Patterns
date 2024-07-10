
#ifndef API_SQL_QUERY_BUILDER_H
#define API_SQL_QUERY_BUILDER_H

#ifdef SQLQUERYBUILDERINHERIT_STATIC_DEFINE
#  define API_SQL_QUERY_BUILDER
#  define SQLQUERYBUILDERINHERIT_NO_EXPORT
#else
#  ifndef API_SQL_QUERY_BUILDER
#    ifdef SqlQueryBuilderInherit_EXPORTS
        /* We are building this library */
#      define API_SQL_QUERY_BUILDER __declspec(dllexport)
#    else
        /* We are using this library */
#      define API_SQL_QUERY_BUILDER __declspec(dllimport)
#    endif
#  endif

#  ifndef SQLQUERYBUILDERINHERIT_NO_EXPORT
#    define SQLQUERYBUILDERINHERIT_NO_EXPORT 
#  endif
#endif

#ifndef SQLQUERYBUILDERINHERIT_DEPRECATED
#  define SQLQUERYBUILDERINHERIT_DEPRECATED __declspec(deprecated)
#endif

#ifndef SQLQUERYBUILDERINHERIT_DEPRECATED_EXPORT
#  define SQLQUERYBUILDERINHERIT_DEPRECATED_EXPORT API_SQL_QUERY_BUILDER SQLQUERYBUILDERINHERIT_DEPRECATED
#endif

#ifndef SQLQUERYBUILDERINHERIT_DEPRECATED_NO_EXPORT
#  define SQLQUERYBUILDERINHERIT_DEPRECATED_NO_EXPORT SQLQUERYBUILDERINHERIT_NO_EXPORT SQLQUERYBUILDERINHERIT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef SQLQUERYBUILDERINHERIT_NO_DEPRECATED
#    define SQLQUERYBUILDERINHERIT_NO_DEPRECATED
#  endif
#endif

#endif /* API_SQL_QUERY_BUILDER_H */
