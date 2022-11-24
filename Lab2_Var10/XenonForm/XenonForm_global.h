#ifndef XENONFORM_GLOBAL_H
#define XENONFORM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XENONFORM_LIBRARY)
#  define XENONFORM_EXPORT Q_DECL_EXPORT
#else
#  define XENONFORM_EXPORT Q_DECL_IMPORT
#endif

#endif // XENONFORM_GLOBAL_H
