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
static const char *ng0 = "E:/rasool/IUT/t4/FPGA/HWs/HW4/HW4_project/Q2_1.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};
static unsigned int ng6[] = {4U, 0U};
static unsigned int ng7[] = {5U, 0U};
static unsigned int ng8[] = {6U, 0U};
static unsigned int ng9[] = {7U, 0U};
static unsigned int ng10[] = {8U, 0U};
static unsigned int ng11[] = {9U, 0U};
static unsigned int ng12[] = {10U, 0U};
static unsigned int ng13[] = {11U, 0U};
static unsigned int ng14[] = {12U, 0U};
static unsigned int ng15[] = {13U, 0U};
static unsigned int ng16[] = {14U, 0U};
static unsigned int ng17[] = {15U, 0U};
static int ng18[] = {32, 0};
static int ng19[] = {1, 0};



static int sp_Winner(char *t1, char *t2)
{
    char t24[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 848);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(34, ng0);

LAB5:    xsi_set_current_line(35, ng0);
    t5 = ((char*)((ng1)));
    t6 = (t1 + 5352);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 6);
    xsi_set_current_line(36, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    xsi_set_current_line(38, ng0);
    t4 = (t1 + 1912U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB6:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB8;

LAB7:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(39, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB10;

LAB9:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB10;

LAB13:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB11;

LAB12:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB14;

LAB15:
LAB16:    xsi_set_current_line(45, ng0);
    t4 = (t1 + 2072U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB18:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB20;

LAB19:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(46, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB22;

LAB21:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB22;

LAB25:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB23;

LAB24:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB26;

LAB27:
LAB28:    xsi_set_current_line(52, ng0);
    t4 = (t1 + 2232U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB30:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB32;

LAB31:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(53, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB34;

LAB33:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB34;

LAB37:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB35;

LAB36:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB38;

LAB39:
LAB40:    xsi_set_current_line(59, ng0);
    t4 = (t1 + 2392U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB42:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB44;

LAB43:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(60, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB46;

LAB45:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB46;

LAB49:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB47;

LAB48:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB50;

LAB51:
LAB52:    xsi_set_current_line(66, ng0);
    t4 = (t1 + 2552U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB54:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB56;

LAB55:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(67, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB58;

LAB57:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB58;

LAB61:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB59;

LAB60:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB62;

LAB63:
LAB64:    xsi_set_current_line(73, ng0);
    t4 = (t1 + 2712U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB66:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB68;

LAB67:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(74, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB70;

LAB69:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB70;

LAB73:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB71;

LAB72:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB74;

LAB75:
LAB76:    xsi_set_current_line(80, ng0);
    t4 = (t1 + 2872U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB78:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB80;

LAB79:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(81, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB82;

LAB81:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB82;

LAB85:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB83;

LAB84:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB86;

LAB87:
LAB88:    xsi_set_current_line(87, ng0);
    t4 = (t1 + 3032U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB90:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB92;

LAB91:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(88, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB94;

LAB93:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB94;

LAB97:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB95;

LAB96:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB98;

LAB99:
LAB100:    xsi_set_current_line(94, ng0);
    t4 = (t1 + 3192U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB102:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB104;

LAB103:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(95, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB106;

LAB105:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB106;

LAB109:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB107;

LAB108:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB110;

LAB111:
LAB112:    xsi_set_current_line(101, ng0);
    t4 = (t1 + 3352U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB114:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB116;

LAB115:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(102, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB118;

LAB117:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB118;

LAB121:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB119;

LAB120:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB122;

LAB123:
LAB124:    xsi_set_current_line(108, ng0);
    t4 = (t1 + 3512U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB126:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB128;

LAB127:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(109, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB130;

LAB129:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB130;

LAB133:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB131;

LAB132:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB134;

LAB135:
LAB136:    xsi_set_current_line(115, ng0);
    t4 = (t1 + 3672U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB138:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB140;

LAB139:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(116, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB142;

LAB141:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB142;

LAB145:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB143;

LAB144:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB146;

LAB147:
LAB148:    xsi_set_current_line(122, ng0);
    t4 = (t1 + 3832U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB150:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB152;

LAB151:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(123, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB154;

LAB153:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB154;

LAB157:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB155;

LAB156:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB158;

LAB159:
LAB160:    xsi_set_current_line(129, ng0);
    t4 = (t1 + 3992U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB162:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB164;

LAB163:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(130, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB166;

LAB165:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB166;

LAB169:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB167;

LAB168:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB170;

LAB171:
LAB172:    xsi_set_current_line(136, ng0);
    t4 = (t1 + 4152U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB174:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB176;

LAB175:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(137, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB178;

LAB177:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB178;

LAB181:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB179;

LAB180:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB182;

LAB183:
LAB184:    xsi_set_current_line(143, ng0);
    t4 = (t1 + 4312U);
    t5 = *((char **)t4);
    t4 = (t1 + 4472U);
    t6 = *((char **)t4);
    t4 = (t2 + 56U);
    t7 = *((char **)t4);
    t8 = (t1 + 1280);
    t9 = xsi_create_subprogram_invocation(t7, 0, t1, t8, 0, t2);
    t10 = (t1 + 5832);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 32);
    t11 = (t1 + 5992);
    xsi_vlogvar_assign_value(t11, t6, 0, 0, 32);

LAB186:    t12 = (t2 + 64U);
    t13 = *((char **)t12);
    t14 = (t13 + 80U);
    t15 = *((char **)t14);
    t16 = (t15 + 272U);
    t17 = *((char **)t16);
    t18 = (t17 + 0U);
    t19 = *((char **)t18);
    t20 = ((int  (*)(char *, char *))t19)(t1, t13);
    if (t20 != 0)
        goto LAB188;

LAB187:    t13 = (t2 + 64U);
    t21 = *((char **)t13);
    t13 = (t1 + 5672);
    t22 = (t13 + 56U);
    t23 = *((char **)t22);
    memcpy(t24, t23, 8);
    t25 = (t1 + 1280);
    t26 = (t2 + 56U);
    t27 = *((char **)t26);
    xsi_delete_subprogram_invocation(t25, t21, t1, t27, t2);
    t28 = (t1 + 5512);
    xsi_vlogvar_assign_value(t28, t24, 0, 0, 6);
    xsi_set_current_line(144, ng0);
    t4 = (t1 + 5512);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t24, 0, 8);
    t10 = (t6 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB190;

LAB189:    t11 = (t9 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB190;

LAB193:    if (*((unsigned int *)t6) > *((unsigned int *)t9))
        goto LAB191;

LAB192:    t13 = (t24 + 4);
    t29 = *((unsigned int *)t13);
    t30 = (~(t29));
    t31 = *((unsigned int *)t24);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB194;

LAB195:
LAB196:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB8:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB6;
    goto LAB1;

LAB10:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB12;

LAB11:    *((unsigned int *)t24) = 1;
    goto LAB12;

LAB14:    xsi_set_current_line(39, ng0);

LAB17:    xsi_set_current_line(40, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(41, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB16;

LAB20:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB18;
    goto LAB1;

LAB22:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB24;

LAB23:    *((unsigned int *)t24) = 1;
    goto LAB24;

LAB26:    xsi_set_current_line(46, ng0);

LAB29:    xsi_set_current_line(47, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(48, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB28;

LAB32:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB30;
    goto LAB1;

LAB34:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB36;

LAB35:    *((unsigned int *)t24) = 1;
    goto LAB36;

LAB38:    xsi_set_current_line(53, ng0);

LAB41:    xsi_set_current_line(54, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(55, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB40;

LAB44:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB42;
    goto LAB1;

LAB46:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB48;

LAB47:    *((unsigned int *)t24) = 1;
    goto LAB48;

LAB50:    xsi_set_current_line(60, ng0);

LAB53:    xsi_set_current_line(61, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(62, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB52;

LAB56:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB54;
    goto LAB1;

LAB58:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB60;

LAB59:    *((unsigned int *)t24) = 1;
    goto LAB60;

LAB62:    xsi_set_current_line(67, ng0);

LAB65:    xsi_set_current_line(68, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(69, ng0);
    t4 = ((char*)((ng6)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB64;

LAB68:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB66;
    goto LAB1;

LAB70:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB72;

LAB71:    *((unsigned int *)t24) = 1;
    goto LAB72;

LAB74:    xsi_set_current_line(74, ng0);

LAB77:    xsi_set_current_line(75, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(76, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB76;

LAB80:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB78;
    goto LAB1;

LAB82:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB84;

LAB83:    *((unsigned int *)t24) = 1;
    goto LAB84;

LAB86:    xsi_set_current_line(81, ng0);

LAB89:    xsi_set_current_line(82, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(83, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB88;

LAB92:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB90;
    goto LAB1;

LAB94:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB96;

LAB95:    *((unsigned int *)t24) = 1;
    goto LAB96;

LAB98:    xsi_set_current_line(88, ng0);

LAB101:    xsi_set_current_line(89, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(90, ng0);
    t4 = ((char*)((ng9)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB100;

LAB104:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB102;
    goto LAB1;

LAB106:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB108;

LAB107:    *((unsigned int *)t24) = 1;
    goto LAB108;

LAB110:    xsi_set_current_line(95, ng0);

LAB113:    xsi_set_current_line(96, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(97, ng0);
    t4 = ((char*)((ng10)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB112;

LAB116:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB114;
    goto LAB1;

LAB118:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB120;

LAB119:    *((unsigned int *)t24) = 1;
    goto LAB120;

LAB122:    xsi_set_current_line(102, ng0);

LAB125:    xsi_set_current_line(103, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(104, ng0);
    t4 = ((char*)((ng11)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB124;

LAB128:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB126;
    goto LAB1;

LAB130:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB132;

LAB131:    *((unsigned int *)t24) = 1;
    goto LAB132;

LAB134:    xsi_set_current_line(109, ng0);

LAB137:    xsi_set_current_line(110, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(111, ng0);
    t4 = ((char*)((ng12)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB136;

LAB140:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB138;
    goto LAB1;

LAB142:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB144;

LAB143:    *((unsigned int *)t24) = 1;
    goto LAB144;

LAB146:    xsi_set_current_line(116, ng0);

LAB149:    xsi_set_current_line(117, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(118, ng0);
    t4 = ((char*)((ng13)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB148;

LAB152:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB150;
    goto LAB1;

LAB154:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB156;

LAB155:    *((unsigned int *)t24) = 1;
    goto LAB156;

LAB158:    xsi_set_current_line(123, ng0);

LAB161:    xsi_set_current_line(124, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(125, ng0);
    t4 = ((char*)((ng14)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB160;

LAB164:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB162;
    goto LAB1;

LAB166:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB168;

LAB167:    *((unsigned int *)t24) = 1;
    goto LAB168;

LAB170:    xsi_set_current_line(130, ng0);

LAB173:    xsi_set_current_line(131, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(132, ng0);
    t4 = ((char*)((ng15)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB172;

LAB176:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB174;
    goto LAB1;

LAB178:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB180;

LAB179:    *((unsigned int *)t24) = 1;
    goto LAB180;

LAB182:    xsi_set_current_line(137, ng0);

LAB185:    xsi_set_current_line(138, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(139, ng0);
    t4 = ((char*)((ng16)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB184;

LAB188:    t12 = (t2 + 48U);
    *((char **)t12) = &&LAB186;
    goto LAB1;

LAB190:    t12 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB192;

LAB191:    *((unsigned int *)t24) = 1;
    goto LAB192;

LAB194:    xsi_set_current_line(144, ng0);

LAB197:    xsi_set_current_line(145, ng0);
    t14 = (t1 + 5512);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 5352);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 6);
    xsi_set_current_line(146, ng0);
    t4 = ((char*)((ng17)));
    t5 = (t1 + 5192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB196;

}

static int sp_Correlation_Func(char *t1, char *t2)
{
    char t7[8];
    char t23[8];
    char t33[8];
    char t40[8];
    char t56[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    char *t57;

LAB0:    t0 = 1;
    xsi_set_current_line(155, ng0);

LAB2:    xsi_set_current_line(156, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t1 + 5672);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 6);
    xsi_set_current_line(157, ng0);
    xsi_set_current_line(157, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t1 + 6152);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 6);

LAB3:    t3 = (t1 + 6152);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng18)));
    memset(t7, 0, 8);
    t8 = (t5 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB5;

LAB4:    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB5;

LAB8:    if (*((unsigned int *)t5) < *((unsigned int *)t6))
        goto LAB6;

LAB7:    t11 = (t7 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t7);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB9;

LAB10:    t0 = 0;

LAB1:    return t0;
LAB5:    t10 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB7;

LAB6:    *((unsigned int *)t7) = 1;
    goto LAB7;

LAB9:    xsi_set_current_line(158, ng0);
    t17 = (t1 + 5672);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t1 + 5832);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    t24 = (t1 + 5832);
    t25 = (t24 + 72U);
    t26 = *((char **)t25);
    t27 = (t1 + 6152);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    xsi_vlog_generic_get_index_select_value(t23, 1, t22, t26, 2, t29, 6, 2);
    t30 = (t1 + 5992);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t34 = (t1 + 5992);
    t35 = (t34 + 72U);
    t36 = *((char **)t35);
    t37 = (t1 + 6152);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    xsi_vlog_generic_get_index_select_value(t33, 1, t32, t36, 2, t39, 6, 2);
    memset(t40, 0, 8);
    t41 = (t23 + 4);
    t42 = (t33 + 4);
    t43 = *((unsigned int *)t23);
    t44 = *((unsigned int *)t33);
    t45 = (t43 ^ t44);
    t46 = *((unsigned int *)t41);
    t47 = *((unsigned int *)t42);
    t48 = (t46 ^ t47);
    t49 = (t45 | t48);
    t50 = *((unsigned int *)t41);
    t51 = *((unsigned int *)t42);
    t52 = (t50 | t51);
    t53 = (~(t52));
    t54 = (t49 & t53);
    if (t54 != 0)
        goto LAB14;

LAB11:    if (t52 != 0)
        goto LAB13;

LAB12:    *((unsigned int *)t40) = 1;

LAB14:    memset(t56, 0, 8);
    xsi_vlog_unsigned_add(t56, 6, t19, 6, t40, 6);
    t57 = (t1 + 5672);
    xsi_vlogvar_assign_value(t57, t56, 0, 0, 6);
    xsi_set_current_line(157, ng0);
    t3 = (t1 + 6152);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng19)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 32, t5, 6, t6, 32);
    t8 = (t1 + 6152);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 6);
    goto LAB3;

LAB13:    t55 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t55) = 1;
    goto LAB14;

}

static void Always_23_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    int t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;

LAB0:    t1 = (t0 + 7072U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 7392);
    *((int *)t2) = 1;
    t3 = (t0 + 7104);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(23, ng0);

LAB5:    xsi_set_current_line(24, ng0);
    t4 = (t0 + 4792U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(28, ng0);
    t2 = (t0 + 6880);
    t3 = (t0 + 848);
    t4 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t4);

LAB12:    t5 = (t0 + 6976);
    t11 = *((char **)t5);
    t12 = (t11 + 80U);
    t13 = *((char **)t12);
    t14 = (t13 + 272U);
    t15 = *((char **)t14);
    t16 = (t15 + 0U);
    t17 = *((char **)t16);
    t18 = ((int  (*)(char *, char *))t17)(t0, t11);

LAB14:    if (t18 != 0)
        goto LAB15;

LAB10:    t11 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t11);

LAB11:    t19 = (t0 + 6976);
    t20 = *((char **)t19);
    t19 = (t0 + 848);
    t21 = (t0 + 6880);
    t22 = 0;
    xsi_delete_subprogram_invocation(t19, t20, t0, t21, t22);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(24, ng0);

LAB9:    xsi_set_current_line(25, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 5192);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 4, 0LL);
    goto LAB8;

LAB13:;
LAB15:    t5 = (t0 + 7072U);
    *((char **)t5) = &&LAB12;
    goto LAB1;

}


extern void work_m_00000000000188183950_2352805378_init()
{
	static char *pe[] = {(void *)Always_23_0};
	static char *se[] = {(void *)sp_Winner,(void *)sp_Correlation_Func};
	xsi_register_didat("work_m_00000000000188183950_2352805378", "isim/TestQ2_2_isim_beh.exe.sim/work/m_00000000000188183950_2352805378.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
