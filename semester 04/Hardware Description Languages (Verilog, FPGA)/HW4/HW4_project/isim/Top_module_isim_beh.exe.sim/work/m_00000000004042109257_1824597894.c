/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "E:/rasool/IUT/t4/FPGA/HWs/HW4/HW4_project/Q1.v";



static void Cont_57_0(char *t0)
{
    char t3[8];
    char t6[16];
    char t9[16];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;

LAB0:    t1 = (t0 + 2664U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 1184U);
    t4 = *((char **)t2);
    t2 = (t0 + 1344U);
    t5 = *((char **)t2);
    xsi_vlog_unsigned_greatereq(t6, 35, t4, 35, t5, 35);
    t2 = (t0 + 1344U);
    t7 = *((char **)t2);
    t2 = (t0 + 1184U);
    t8 = *((char **)t2);
    xsi_vlog_unsigned_greatereq(t9, 35, t7, 35, t8, 35);
    xsi_vlogtype_concat(t3, 2, 2, 2U, t9, 1, t6, 1);
    t2 = (t0 + 3064);
    t10 = (t2 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memset(t13, 0, 8);
    t14 = 3U;
    t15 = t14;
    t16 = (t3 + 4);
    t17 = *((unsigned int *)t3);
    t14 = (t14 & t17);
    t18 = *((unsigned int *)t16);
    t15 = (t15 & t18);
    t19 = (t13 + 4);
    t20 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t20 | t14);
    t21 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t21 | t15);
    xsi_driver_vfirst_trans(t2, 0, 1);
    t22 = (t0 + 2984);
    *((int *)t22) = 1;

LAB1:    return;
}


extern void work_m_00000000004042109257_1824597894_init()
{
	static char *pe[] = {(void *)Cont_57_0};
	xsi_register_didat("work_m_00000000004042109257_1824597894", "isim/Top_module_isim_beh.exe.sim/work/m_00000000004042109257_1824597894.didat");
	xsi_register_executes(pe);
}
