/* Declarations for use by hardware emulation.  */
#ifndef QEMU_HW_H
#define QEMU_HW_H

#include "qemu-common.h"

#if defined(TARGET_PHYS_ADDR_BITS) && !defined(NEED_CPU_H)
#include "cpu-common.h"
#endif

#include "ioport.h"
#include "irq.h"
#include "qemu-file.h"
#include "vmstate.h"

#ifdef NEED_CPU_H
#if TARGET_LONG_BITS == 64
#define qemu_put_betl qemu_put_be64
#define qemu_get_betl qemu_get_be64
#define qemu_put_betls qemu_put_be64s
#define qemu_get_betls qemu_get_be64s
#define qemu_put_sbetl qemu_put_sbe64
#define qemu_get_sbetl qemu_get_sbe64
#define qemu_put_sbetls qemu_put_sbe64s
#define qemu_get_sbetls qemu_get_sbe64s
#else
#define qemu_put_betl qemu_put_be32
#define qemu_get_betl qemu_get_be32
#define qemu_put_betls qemu_put_be32s
#define qemu_get_betls qemu_get_be32s
#define qemu_put_sbetl qemu_put_sbe32
#define qemu_get_sbetl qemu_get_sbe32
#define qemu_put_sbetls qemu_put_sbe32s
#define qemu_get_sbetls qemu_get_sbe32s
#endif
#endif

typedef void QEMUResetHandler(void *opaque);

void qemu_register_reset(QEMUResetHandler *func, void *opaque);
void qemu_unregister_reset(QEMUResetHandler *func, void *opaque);

/* handler to set the boot_device order for a specific type of QEMUMachine */
/* return 0 if success */
typedef int QEMUBootSetHandler(void *opaque, const char *boot_devices);
void qemu_register_boot_set(QEMUBootSetHandler *func, void *opaque);
int qemu_boot_set(const char *boot_devices);

#ifdef NEED_CPU_H
#if TARGET_LONG_BITS == 64
#define VMSTATE_UINTTL_V(_f, _s, _v)                                  \
    VMSTATE_UINT64_V(_f, _s, _v)
#define VMSTATE_UINTTL_ARRAY_V(_f, _s, _n, _v)                        \
    VMSTATE_UINT64_ARRAY_V(_f, _s, _n, _v)
#else
#define VMSTATE_UINTTL_V(_f, _s, _v)                                  \
    VMSTATE_UINT32_V(_f, _s, _v)
#define VMSTATE_UINTTL_ARRAY_V(_f, _s, _n, _v)                        \
    VMSTATE_UINT32_ARRAY_V(_f, _s, _n, _v)
#endif
#define VMSTATE_UINTTL(_f, _s)                                        \
    VMSTATE_UINTTL_V(_f, _s, 0)
#define VMSTATE_UINTTL_ARRAY(_f, _s, _n)                              \
    VMSTATE_UINTTL_ARRAY_V(_f, _s, _n, 0)

#endif

#endif
