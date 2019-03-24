#ifndef CCPORT_MACH_I386__STRUCTS_H_
#define CCPORT_MACH_I386__STRUCTS_H_

#include <stdint.h>

#ifndef __uint8_t
#define ccport_uint8_t_defined
#define __uint8_t uint8_t
#endif /* __uint8_t */

#ifndef __uint16_t
#define ccport_uint16_t_defined
#define __uint16_t uint16_t
#endif /* __uint16_t */

#ifndef __uint32_t
#define ccport_uint32_t_defined
#define __uint32_t uint32_t
#endif /* __uint32_t */

#ifndef __uint64_t
#define ccport_uint64_t_defined
#define __uint64_t uint64_t
#endif /* __uint64_t */

#include_next <mach/i386/_structs.h>

#ifdef ccport_uint8_t_defined
#undef ccport_uint8_t_defined
#undef __uint8_t
#endif /* ccport_uint8_t_defined */

#ifdef ccport_uint16_t_defined
#undef ccport_uint16_t_defined
#undef __uint16_t
#endif /* ccport_uint16_t_defined */

#ifdef ccport_uint32_t_defined
#undef ccport_uint32_t_defined
#undef __uint32_t
#endif /* ccport_uint32_t_defined */

#ifdef ccport_uint64_t_defined
#undef ccport_uint64_t_defined
#undef __uint64_t
#endif /* ccport_uint64_t_defined */

/* https://github.com/apple/darwin-xnu/blob/xnu-4903.221.2/osfmk/mach/i386/_structs.h#L235 */
#ifndef _STRUCT_YMM_REG
#define _STRUCT_YMM_REG struct ymm_reg
_STRUCT_YMM_REG {
    char ymm_reg[32];
};
#endif /* _STRUCT_YMM_REG */

/* https://github.com/apple/darwin-xnu/blob/xnu-4903.221.2/osfmk/mach/i386/_structs.h#L251 */
#ifndef _STRUCT_ZMM_REG
#define _STRUCT_ZMM_REG        struct zmm_reg
_STRUCT_ZMM_REG {
    char zmm_reg[64];
};
#endif /* _STRUCT_ZMM_REG */

/* https://github.com/apple/darwin-xnu/blob/xnu-4903.221.2/osfmk/mach/i386/_structs.h#L265 */
#ifndef _STRUCT_OPMASK_REG
#define _STRUCT_OPMASK_REG struct opmask_reg
_STRUCT_OPMASK_REG {
    char opmask_reg[8];
};
#endif /* _STRUCT_OPMASK_REG */

/* https://github.com/apple/darwin-xnu/blob/xnu-4903.221.2/osfmk/mach/i386/_structs.h#L366 */
#ifndef _STRUCT_X86_AVX512_STATE32
#define _STRUCT_X86_AVX512_STATE32 struct __darwin_i386_avx512_state
_STRUCT_X86_AVX512_STATE32 {
    int __fpu_reserved[2];
    _STRUCT_FP_CONTROL __fpu_fcw;
    _STRUCT_FP_STATUS __fpu_fsw;
    uint8_t __fpu_ftw;
    uint8_t __fpu_rsrv1;
    uint16_t __fpu_fop;
    uint32_t __fpu_ip;
    uint16_t __fpu_cs;
    uint16_t __fpu_rsrv2;
    uint32_t __fpu_dp;
    uint16_t __fpu_ds;
    uint16_t __fpu_rsrv3;
    uint32_t __fpu_mxcsr;
    uint32_t __fpu_mxcsrmask;
    _STRUCT_MMST_REG __fpu_stmm0;
    _STRUCT_MMST_REG __fpu_stmm1;
    _STRUCT_MMST_REG __fpu_stmm2;
    _STRUCT_MMST_REG __fpu_stmm3;
    _STRUCT_MMST_REG __fpu_stmm4;
    _STRUCT_MMST_REG __fpu_stmm5;
    _STRUCT_MMST_REG __fpu_stmm6;
    _STRUCT_MMST_REG __fpu_stmm7;
    _STRUCT_XMM_REG __fpu_xmm0;
    _STRUCT_XMM_REG __fpu_xmm1;
    _STRUCT_XMM_REG __fpu_xmm2;
    _STRUCT_XMM_REG __fpu_xmm3;
    _STRUCT_XMM_REG __fpu_xmm4;
    _STRUCT_XMM_REG __fpu_xmm5;
    _STRUCT_XMM_REG __fpu_xmm6;
    _STRUCT_XMM_REG __fpu_xmm7;
    char __fpu_rsrv4[14 * 16];
    int __fpu_reserved1;
    char __avx_reserved1[64];
    _STRUCT_XMM_REG __fpu_ymmh0;
    _STRUCT_XMM_REG __fpu_ymmh1;
    _STRUCT_XMM_REG __fpu_ymmh2;
    _STRUCT_XMM_REG __fpu_ymmh3;
    _STRUCT_XMM_REG __fpu_ymmh4;
    _STRUCT_XMM_REG __fpu_ymmh5;
    _STRUCT_XMM_REG __fpu_ymmh6;
    _STRUCT_XMM_REG __fpu_ymmh7;
    _STRUCT_OPMASK_REG __fpu_k0;
    _STRUCT_OPMASK_REG __fpu_k1;
    _STRUCT_OPMASK_REG __fpu_k2;
    _STRUCT_OPMASK_REG __fpu_k3;
    _STRUCT_OPMASK_REG __fpu_k4;
    _STRUCT_OPMASK_REG __fpu_k5;
    _STRUCT_OPMASK_REG __fpu_k6;
    _STRUCT_OPMASK_REG __fpu_k7;
    _STRUCT_YMM_REG __fpu_zmmh0;
    _STRUCT_YMM_REG __fpu_zmmh1;
    _STRUCT_YMM_REG __fpu_zmmh2;
    _STRUCT_YMM_REG __fpu_zmmh3;
    _STRUCT_YMM_REG __fpu_zmmh4;
    _STRUCT_YMM_REG __fpu_zmmh5;
    _STRUCT_YMM_REG __fpu_zmmh6;
    _STRUCT_YMM_REG __fpu_zmmh7;
};
#endif /* _STRUCT_X86_AVX512_STATE32 */

/* https://github.com/apple/darwin-xnu/blob/xnu-4903.221.2/osfmk/mach/i386/_structs.h#L807 */
#define _STRUCT_X86_AVX512_STATE64 struct __darwin_x86_avx512_state64
_STRUCT_X86_AVX512_STATE64 {
    int __fpu_reserved[2];
    _STRUCT_FP_CONTROL __fpu_fcw;
    _STRUCT_FP_STATUS __fpu_fsw;
    uint8_t __fpu_ftw;
    uint8_t __fpu_rsrv1;
    uint16_t __fpu_fop;
    uint32_t __fpu_ip;
    uint16_t __fpu_cs;
    uint16_t __fpu_rsrv2;
    uint32_t __fpu_dp;
    uint16_t __fpu_ds;
    uint16_t __fpu_rsrv3;
    uint32_t __fpu_mxcsr;
    uint32_t __fpu_mxcsrmask;
    _STRUCT_MMST_REG __fpu_stmm0;
    _STRUCT_MMST_REG __fpu_stmm1;
    _STRUCT_MMST_REG __fpu_stmm2;
    _STRUCT_MMST_REG __fpu_stmm3;
    _STRUCT_MMST_REG __fpu_stmm4;
    _STRUCT_MMST_REG __fpu_stmm5;
    _STRUCT_MMST_REG __fpu_stmm6;
    _STRUCT_MMST_REG __fpu_stmm7;
    _STRUCT_XMM_REG __fpu_xmm0;
    _STRUCT_XMM_REG __fpu_xmm1;
    _STRUCT_XMM_REG __fpu_xmm2;
    _STRUCT_XMM_REG __fpu_xmm3;
    _STRUCT_XMM_REG __fpu_xmm4;
    _STRUCT_XMM_REG __fpu_xmm5;
    _STRUCT_XMM_REG __fpu_xmm6;
    _STRUCT_XMM_REG __fpu_xmm7;
    _STRUCT_XMM_REG __fpu_xmm8;
    _STRUCT_XMM_REG __fpu_xmm9;
    _STRUCT_XMM_REG __fpu_xmm10;
    _STRUCT_XMM_REG __fpu_xmm11;
    _STRUCT_XMM_REG __fpu_xmm12;
    _STRUCT_XMM_REG __fpu_xmm13;
    _STRUCT_XMM_REG __fpu_xmm14;
    _STRUCT_XMM_REG __fpu_xmm15;
    char __fpu_rsrv4[6 * 16];
    int __fpu_reserved1;
    char __avx_reserved1[64];
    _STRUCT_XMM_REG __fpu_ymmh0;
    _STRUCT_XMM_REG __fpu_ymmh1;
    _STRUCT_XMM_REG __fpu_ymmh2;
    _STRUCT_XMM_REG __fpu_ymmh3;
    _STRUCT_XMM_REG __fpu_ymmh4;
    _STRUCT_XMM_REG __fpu_ymmh5;
    _STRUCT_XMM_REG __fpu_ymmh6;
    _STRUCT_XMM_REG __fpu_ymmh7;
    _STRUCT_XMM_REG __fpu_ymmh8;
    _STRUCT_XMM_REG __fpu_ymmh9;
    _STRUCT_XMM_REG __fpu_ymmh10;
    _STRUCT_XMM_REG __fpu_ymmh11;
    _STRUCT_XMM_REG __fpu_ymmh12;
    _STRUCT_XMM_REG __fpu_ymmh13;
    _STRUCT_XMM_REG __fpu_ymmh14;
    _STRUCT_XMM_REG __fpu_ymmh15;
    _STRUCT_OPMASK_REG __fpu_k0;
    _STRUCT_OPMASK_REG __fpu_k1;
    _STRUCT_OPMASK_REG __fpu_k2;
    _STRUCT_OPMASK_REG __fpu_k3;
    _STRUCT_OPMASK_REG __fpu_k4;
    _STRUCT_OPMASK_REG __fpu_k5;
    _STRUCT_OPMASK_REG __fpu_k6;
    _STRUCT_OPMASK_REG __fpu_k7;
    _STRUCT_YMM_REG __fpu_zmmh0;
    _STRUCT_YMM_REG __fpu_zmmh1;
    _STRUCT_YMM_REG __fpu_zmmh2;
    _STRUCT_YMM_REG __fpu_zmmh3;
    _STRUCT_YMM_REG __fpu_zmmh4;
    _STRUCT_YMM_REG __fpu_zmmh5;
    _STRUCT_YMM_REG __fpu_zmmh6;
    _STRUCT_YMM_REG __fpu_zmmh7;
    _STRUCT_YMM_REG __fpu_zmmh8;
    _STRUCT_YMM_REG __fpu_zmmh9;
    _STRUCT_YMM_REG __fpu_zmmh10;
    _STRUCT_YMM_REG __fpu_zmmh11;
    _STRUCT_YMM_REG __fpu_zmmh12;
    _STRUCT_YMM_REG __fpu_zmmh13;
    _STRUCT_YMM_REG __fpu_zmmh14;
    _STRUCT_YMM_REG __fpu_zmmh15;
    _STRUCT_ZMM_REG __fpu_zmm16;
    _STRUCT_ZMM_REG __fpu_zmm17;
    _STRUCT_ZMM_REG __fpu_zmm18;
    _STRUCT_ZMM_REG __fpu_zmm19;
    _STRUCT_ZMM_REG __fpu_zmm20;
    _STRUCT_ZMM_REG __fpu_zmm21;
    _STRUCT_ZMM_REG __fpu_zmm22;
    _STRUCT_ZMM_REG __fpu_zmm23;
    _STRUCT_ZMM_REG __fpu_zmm24;
    _STRUCT_ZMM_REG __fpu_zmm25;
    _STRUCT_ZMM_REG __fpu_zmm26;
    _STRUCT_ZMM_REG __fpu_zmm27;
    _STRUCT_ZMM_REG __fpu_zmm28;
    _STRUCT_ZMM_REG __fpu_zmm29;
    _STRUCT_ZMM_REG __fpu_zmm30;
    _STRUCT_ZMM_REG __fpu_zmm31;
};

#endif /* CCPORT_MACH_I386__STRUCTS_H_ */
