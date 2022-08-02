
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#define link_GTK      G_MODULE_EXPORT
#define __Const       __attribute__((const))
#define __deprecated  __attribute__((deprecated))
#define __unavailable __attribute__((unavailable))
#define __noreturn    __attribute__((noreturn))
#define __Section(X)  __attribute__((section(X)))
#define ECAPI(X)      __attribute__((section("EC.API."#X)))
#define weak          __attribute__((weak))
#define unused        __attribute__((unused))
#define compulsory    __attribute__((warn_unused_result))
#if defined(XC8) || defined(XC16) || defined(XC32)
#define constructor
#define destructor
#define __cold
#define __hot
#else
#define constructor     __attribute__((constructor))
#define destructor      __attribute__((destructor))
#define __cold          __attribute__((cold))
#define __hot           __attribute__((hot))
#endif

#ifdef __cplusplus
}
#endif
