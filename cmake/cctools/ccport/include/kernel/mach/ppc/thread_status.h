#ifndef CCPORT_MACH_PPC_THREAD_STATUS_H_
#define CCPORT_MACH_PPC_THREAD_STATUS_H_

#include_next <mach/ppc/thread_status.h>

#pragma pack(4)
struct ppc_thread_state64 {
    unsigned long long srr0;
    unsigned long long srr1;
    unsigned long long r0;
    unsigned long long r1;
    unsigned long long r2;
    unsigned long long r3;
    unsigned long long r4;
    unsigned long long r5;
    unsigned long long r6;
    unsigned long long r7;
    unsigned long long r8;
    unsigned long long r9;
    unsigned long long r10;
    unsigned long long r11;
    unsigned long long r12;
    unsigned long long r13;
    unsigned long long r14;
    unsigned long long r15;
    unsigned long long r16;
    unsigned long long r17;
    unsigned long long r18;
    unsigned long long r19;
    unsigned long long r20;
    unsigned long long r21;
    unsigned long long r22;
    unsigned long long r23;
    unsigned long long r24;
    unsigned long long r25;
    unsigned long long r26;
    unsigned long long r27;
    unsigned long long r28;
    unsigned long long r29;
    unsigned long long r30;
    unsigned long long r31;

    unsigned int cr;
    unsigned long long xer;
    unsigned long long lr;
    unsigned long long ctr;

    unsigned int vrsave;
};
#pragma pack()

typedef struct ppc_thread_state64 ppc_thread_state64_t;

#endif /* CCPORT_MACH_PPC_THREAD_STATUS_H_ */
