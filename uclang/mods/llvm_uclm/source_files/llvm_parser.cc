
@begin
include "ucl_llvm.h"
@end

/*
 * constants and definitions
 */

// - llvm type strings -
const char *c_type_strings[] =
{/*{{{*/
  "void",
  "i8",
  "u8",
  "i16",
  "u16",
  "i32",
  "u32",
  "i64",
  "u64",
  "f32",
  "f64",
  "ptr",
};/*}}}*/

const unsigned c_type_str_lengths[] =
{/*{{{*/
  4,
  2,
  2,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
};/*}}}*/

/*
 * methods of generated structures
 */

// -- llvm_parser_s --
@begin
   methods llvm_parser_s
@end

unsigned llvm_parser_s::recognize_type(unsigned a_length,const char *a_data)
{/*{{{*/
#define GET_LLVM_TYPE_NEXT_CHAR() \
{\
   if (input_idx < a_length) {\
      in_char = (unsigned char)a_data[input_idx];\
   }\
   else {\
      in_char = '\0';\
   }\
}

#define CLOSE_LLVM_TYPE_CHAR(RET_TERM_IDX) \
{\
   if (in_char == '\0') {\
      return RET_TERM_IDX;\
   }\
\
   input_idx++;\
}

   unsigned input_idx = 0;
   unsigned short in_char;

// - STATE 0 - 
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 102)
      goto state_1_label;

   if (in_char == 105)
      goto state_2_label;

   if (in_char == 117)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 1 - 
state_1_label:
   CLOSE_LLVM_TYPE_CHAR(c_idx_not_exist);
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 51)
      goto state_4_label;

   if (in_char == 54)
      goto state_5_label;

   return c_idx_not_exist;

// - STATE 2 - 
state_2_label:
   CLOSE_LLVM_TYPE_CHAR(c_idx_not_exist);
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 49)
      goto state_6_label;

   if (in_char == 51)
      goto state_7_label;

   if (in_char == 54)
      goto state_8_label;

   if (in_char == 56)
      goto state_9_label;

   return c_idx_not_exist;

// - STATE 3 - 
state_3_label:
   CLOSE_LLVM_TYPE_CHAR(c_idx_not_exist);
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 49)
      goto state_10_label;

   if (in_char == 51)
      goto state_11_label;

   if (in_char == 54)
      goto state_12_label;

   if (in_char == 56)
      goto state_13_label;

   return c_idx_not_exist;

// - STATE 4 - 
state_4_label:
   CLOSE_LLVM_TYPE_CHAR(c_idx_not_exist);
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 50)
      goto state_14_label;

   return c_idx_not_exist;

// - STATE 5 - 
state_5_label:
   CLOSE_LLVM_TYPE_CHAR(c_idx_not_exist);
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 52)
      goto state_15_label;

   return c_idx_not_exist;

// - STATE 6 - 
state_6_label:
   CLOSE_LLVM_TYPE_CHAR(c_idx_not_exist);
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 54)
      goto state_16_label;

   return c_idx_not_exist;

// - STATE 7 - 
state_7_label:
   CLOSE_LLVM_TYPE_CHAR(c_idx_not_exist);
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 50)
      goto state_17_label;

   return c_idx_not_exist;

// - STATE 8 - 
state_8_label:
   CLOSE_LLVM_TYPE_CHAR(c_idx_not_exist);
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 52)
      goto state_18_label;

   return c_idx_not_exist;

// - STATE 9 - 
state_9_label:
   CLOSE_LLVM_TYPE_CHAR(c_var_type_i8);
   return c_var_type_i8;


// - STATE 10 - 
state_10_label:
   CLOSE_LLVM_TYPE_CHAR(c_idx_not_exist);
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 54)
      goto state_19_label;

   return c_idx_not_exist;

// - STATE 11 - 
state_11_label:
   CLOSE_LLVM_TYPE_CHAR(c_idx_not_exist);
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 50)
      goto state_20_label;

   return c_idx_not_exist;

// - STATE 12 - 
state_12_label:
   CLOSE_LLVM_TYPE_CHAR(c_idx_not_exist);
   GET_LLVM_TYPE_NEXT_CHAR();

   if (in_char == 52)
      goto state_21_label;

   return c_idx_not_exist;

// - STATE 13 - 
state_13_label:
   CLOSE_LLVM_TYPE_CHAR(c_var_type_u8);
   return c_var_type_u8;

// - STATE 14 - 
state_14_label:
   CLOSE_LLVM_TYPE_CHAR(c_var_type_f32);
   return c_var_type_f32;

// - STATE 15 - 
state_15_label:
   CLOSE_LLVM_TYPE_CHAR(c_var_type_f64);
   return c_var_type_f64;

// - STATE 16 - 
state_16_label:
   CLOSE_LLVM_TYPE_CHAR(c_var_type_i16);
   return c_var_type_i16;

// - STATE 17 - 
state_17_label:
   CLOSE_LLVM_TYPE_CHAR(c_var_type_i32);
   return c_var_type_i32;

// - STATE 18 - 
state_18_label:
   CLOSE_LLVM_TYPE_CHAR(c_var_type_i64);
   return c_var_type_i64;

// - STATE 19 - 
state_19_label:
   CLOSE_LLVM_TYPE_CHAR(c_var_type_u16);
   return c_var_type_u16;

// - STATE 20 - 
state_20_label:
   CLOSE_LLVM_TYPE_CHAR(c_var_type_u32);
   return c_var_type_u32;

// - STATE 21 - 
state_21_label:
   CLOSE_LLVM_TYPE_CHAR(c_var_type_u64);
   return c_var_type_u64;

}/*}}}*/

unsigned llvm_parser_s::recognize_terminal(unsigned &input_idx)
{/*{{{*/
  unsigned source_string_length = source_string.size - 1;

#define GET_LLVM_NEXT_CHAR() \
  {\
    if (input_idx < source_string_length) {\
      in_char = (unsigned char)source_string[input_idx];\
    }\
    else {\
      in_char = '\0';\
    }\
  }

#define CLOSE_LLVM_CHAR(RET_TERM_IDX) \
  {\
    if (in_char == '\0') {\
      return RET_TERM_IDX;\
    }\
    \
    input_idx++;\
  }

   unsigned short in_char;

// - STATE 0 - 
   GET_LLVM_NEXT_CHAR();

   if (in_char == 0)
      goto state_1_label;

   if (in_char >= 9 && in_char < 11)
      goto state_41_label;

   if (in_char == 32)
      goto state_41_label;

   if (in_char == 33)
      goto state_2_label;

   if (in_char == 35)
      goto state_3_label;

   if (in_char == 37)
      goto state_4_label;

   if (in_char == 38)
      goto state_5_label;

   if (in_char == 39)
      goto state_6_label;

   if (in_char == 40)
      goto state_7_label;

   if (in_char == 41)
      goto state_8_label;

   if (in_char == 42)
      goto state_9_label;

   if (in_char == 43)
      goto state_10_label;

   if (in_char == 44)
      goto state_11_label;

   if (in_char == 45)
      goto state_12_label;

   if (in_char == 46)
      goto state_13_label;

   if (in_char == 47)
      goto state_14_label;

   if (in_char == 48)
      goto state_15_label;

   if (in_char >= 49 && in_char < 58)
      goto state_16_label;

   if (in_char == 58)
      goto state_17_label;

   if (in_char == 59)
      goto state_18_label;

   if (in_char == 60)
      goto state_19_label;

   if (in_char == 61)
      goto state_20_label;

   if (in_char == 62)
      goto state_21_label;

   if (in_char == 63)
      goto state_22_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 91)
      goto state_23_label;

   if (in_char == 93)
      goto state_24_label;

   if (in_char == 94)
      goto state_25_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char == 97)
      goto state_26_label;

   if (in_char == 98)
      goto state_27_label;

   if (in_char == 99)
      goto state_28_label;

   if (in_char == 100)
      goto state_29_label;

   if (in_char == 101)
      goto state_30_label;

   if (in_char == 102)
      goto state_31_label;

   if (in_char >= 103 && in_char < 105)
      goto state_26_label;

   if (in_char == 105)
      goto state_32_label;

   if (in_char >= 106 && in_char < 114)
      goto state_26_label;

   if (in_char == 114)
      goto state_33_label;

   if (in_char >= 115 && in_char < 117)
      goto state_26_label;

   if (in_char == 117)
      goto state_34_label;

   if (in_char == 118)
      goto state_35_label;

   if (in_char == 119)
      goto state_36_label;

   if (in_char >= 120 && in_char < 123)
      goto state_26_label;

   if (in_char == 123)
      goto state_37_label;

   if (in_char == 124)
      goto state_38_label;

   if (in_char == 125)
      goto state_39_label;

   if (in_char == 126)
      goto state_40_label;

   return c_idx_not_exist;

// - STATE 1 - 
state_1_label:
   CLOSE_LLVM_CHAR(70);
   return 70;

// - STATE 2 - 
state_2_label:
   CLOSE_LLVM_CHAR(62);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 61)
      goto state_43_label;

   return 62;

// - STATE 3 - 
state_3_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char < 10)
      goto state_3_label;

   if (in_char == 10)
      goto state_44_label;

   if (in_char >= 11 && in_char < 257)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 4 - 
state_4_label:
   CLOSE_LLVM_CHAR(59);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 61)
      goto state_45_label;

   return 59;

// - STATE 5 - 
state_5_label:
   CLOSE_LLVM_CHAR(43);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 38)
      goto state_46_label;

   if (in_char == 61)
      goto state_47_label;

   return 43;

// - STATE 6 - 
state_6_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char < 92)
      goto state_49_label;

   if (in_char == 92)
      goto state_48_label;

   if (in_char >= 93 && in_char < 257)
      goto state_49_label;

   return c_idx_not_exist;

// - STATE 7 - 
state_7_label:
   CLOSE_LLVM_CHAR(14);
   return 14;

// - STATE 8 - 
state_8_label:
   CLOSE_LLVM_CHAR(15);
   return 15;

// - STATE 9 - 
state_9_label:
   CLOSE_LLVM_CHAR(57);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 61)
      goto state_50_label;

   return 57;

// - STATE 10 - 
state_10_label:
   CLOSE_LLVM_CHAR(54);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 43)
      goto state_51_label;

   if (in_char == 61)
      goto state_52_label;

   return 54;

// - STATE 11 - 
state_11_label:
   CLOSE_LLVM_CHAR(20);
   return 20;

// - STATE 12 - 
state_12_label:
   CLOSE_LLVM_CHAR(55);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 45)
      goto state_53_label;

   if (in_char == 61)
      goto state_54_label;

   return 55;

// - STATE 13 - 
state_13_label:
   CLOSE_LLVM_CHAR(56);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_55_label;

   return 56;

// - STATE 14 - 
state_14_label:
   CLOSE_LLVM_CHAR(58);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 42)
      goto state_56_label;

   if (in_char == 47)
      goto state_57_label;

   if (in_char == 61)
      goto state_58_label;

   return 58;

// - STATE 15 - 
state_15_label:
   CLOSE_LLVM_CHAR(4);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 46)
      goto state_59_label;

   if (in_char >= 48 && in_char < 56)
      goto state_60_label;

   if (in_char >= 56 && in_char < 58)
      goto state_42_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 76)
      goto state_63_label;

   if (in_char == 88)
      goto state_64_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   if (in_char == 108)
      goto state_63_label;

   if (in_char == 120)
      goto state_64_label;

   return 4;

// - STATE 16 - 
state_16_label:
   CLOSE_LLVM_CHAR(5);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 46)
      goto state_59_label;

   if (in_char >= 48 && in_char < 58)
      goto state_16_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 76)
      goto state_65_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   if (in_char == 108)
      goto state_65_label;

   return 5;

// - STATE 17 - 
state_17_label:
   CLOSE_LLVM_CHAR(64);
   return 64;

// - STATE 18 - 
state_18_label:
   CLOSE_LLVM_CHAR(21);
   return 21;

// - STATE 19 - 
state_19_label:
   CLOSE_LLVM_CHAR(49);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 60)
      goto state_66_label;

   if (in_char == 61)
      goto state_67_label;

   return 49;

// - STATE 20 - 
state_20_label:
   CLOSE_LLVM_CHAR(30);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 61)
      goto state_68_label;

   return 30;

// - STATE 21 - 
state_21_label:
   CLOSE_LLVM_CHAR(48);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 61)
      goto state_69_label;

   if (in_char == 62)
      goto state_70_label;

   return 48;

// - STATE 22 - 
state_22_label:
   CLOSE_LLVM_CHAR(63);
   return 63;

// - STATE 23 - 
state_23_label:
   CLOSE_LLVM_CHAR(18);
   return 18;

// - STATE 24 - 
state_24_label:
   CLOSE_LLVM_CHAR(19);
   return 19;

// - STATE 25 - 
state_25_label:
   CLOSE_LLVM_CHAR(45);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 61)
      goto state_71_label;

   return 45;

// - STATE 26 - 
state_26_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 27 - 
state_27_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 114)
      goto state_26_label;

   if (in_char == 114)
      goto state_72_label;

   if (in_char >= 115 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 28 - 
state_28_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 111)
      goto state_26_label;

   if (in_char == 111)
      goto state_73_label;

   if (in_char >= 112 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 29 - 
state_29_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 111)
      goto state_26_label;

   if (in_char == 111)
      goto state_74_label;

   if (in_char >= 112 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 30 - 
state_30_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_75_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 31 - 
state_31_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 51)
      goto state_26_label;

   if (in_char == 51)
      goto state_76_label;

   if (in_char >= 52 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_77_label;

   if (in_char >= 55 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 32 - 
state_32_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 48)
      goto state_26_label;

   if (in_char == 49)
      goto state_78_label;

   if (in_char == 50)
      goto state_26_label;

   if (in_char == 51)
      goto state_79_label;

   if (in_char >= 52 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_80_label;

   if (in_char == 55)
      goto state_26_label;

   if (in_char == 56)
      goto state_81_label;

   if (in_char == 57)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 102)
      goto state_26_label;

   if (in_char == 102)
      goto state_82_label;

   if (in_char >= 103 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 33 - 
state_33_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_83_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 34 - 
state_34_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 48)
      goto state_26_label;

   if (in_char == 49)
      goto state_84_label;

   if (in_char == 50)
      goto state_26_label;

   if (in_char == 51)
      goto state_85_label;

   if (in_char >= 52 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_86_label;

   if (in_char == 55)
      goto state_26_label;

   if (in_char == 56)
      goto state_81_label;

   if (in_char == 57)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 35 - 
state_35_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 111)
      goto state_26_label;

   if (in_char == 111)
      goto state_87_label;

   if (in_char >= 112 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 36 - 
state_36_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 104)
      goto state_26_label;

   if (in_char == 104)
      goto state_88_label;

   if (in_char >= 105 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 37 - 
state_37_label:
   CLOSE_LLVM_CHAR(16);
   return 16;

// - STATE 38 - 
state_38_label:
   CLOSE_LLVM_CHAR(44);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 61)
      goto state_89_label;

   if (in_char == 124)
      goto state_90_label;

   return 44;

// - STATE 39 - 
state_39_label:
   CLOSE_LLVM_CHAR(17);
   return 17;

// - STATE 40 - 
state_40_label:
   CLOSE_LLVM_CHAR(65);
   return 65;

// - STATE 41 - 
state_41_label:
   CLOSE_LLVM_CHAR(66);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_41_label;

   if (in_char == 32)
      goto state_41_label;

   return 66;

// - STATE 42 - 
state_42_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 46)
      goto state_59_label;

   if (in_char >= 48 && in_char < 58)
      goto state_42_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   return c_idx_not_exist;

// - STATE 43 - 
state_43_label:
   CLOSE_LLVM_CHAR(47);
   return 47;

// - STATE 44 - 
state_44_label:
   CLOSE_LLVM_CHAR(67);
   return 67;

// - STATE 45 - 
state_45_label:
   CLOSE_LLVM_CHAR(35);
   return 35;

// - STATE 46 - 
state_46_label:
   CLOSE_LLVM_CHAR(41);
   return 41;

// - STATE 47 - 
state_47_label:
   CLOSE_LLVM_CHAR(38);
   return 38;

// - STATE 48 - 
state_48_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 34)
      goto state_91_label;

   if (in_char == 39)
      goto state_92_label;

   if (in_char >= 48 && in_char < 56)
      goto state_93_label;

   if (in_char == 63)
      goto state_91_label;

   if (in_char == 92)
      goto state_91_label;

   if (in_char >= 97 && in_char < 99)
      goto state_91_label;

   if (in_char == 102)
      goto state_91_label;

   if (in_char == 110)
      goto state_91_label;

   if (in_char == 114)
      goto state_91_label;

   if (in_char == 116)
      goto state_91_label;

   if (in_char == 118)
      goto state_91_label;

   if (in_char == 120)
      goto state_94_label;

   return c_idx_not_exist;

// - STATE 49 - 
state_49_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 39)
      goto state_95_label;

   return c_idx_not_exist;

// - STATE 50 - 
state_50_label:
   CLOSE_LLVM_CHAR(33);
   return 33;

// - STATE 51 - 
state_51_label:
   CLOSE_LLVM_CHAR(60);
   return 60;

// - STATE 52 - 
state_52_label:
   CLOSE_LLVM_CHAR(31);
   return 31;

// - STATE 53 - 
state_53_label:
   CLOSE_LLVM_CHAR(61);
   return 61;

// - STATE 54 - 
state_54_label:
   CLOSE_LLVM_CHAR(32);
   return 32;

// - STATE 55 - 
state_55_label:
   CLOSE_LLVM_CHAR(11);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_55_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   return 11;

// - STATE 56 - 
state_56_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char < 42)
      goto state_56_label;

   if (in_char == 42)
      goto state_96_label;

   if (in_char >= 43 && in_char < 257)
      goto state_56_label;

   return c_idx_not_exist;

// - STATE 57 - 
state_57_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char < 10)
      goto state_57_label;

   if (in_char == 10)
      goto state_97_label;

   if (in_char >= 11 && in_char < 257)
      goto state_57_label;

   return c_idx_not_exist;

// - STATE 58 - 
state_58_label:
   CLOSE_LLVM_CHAR(34);
   return 34;

// - STATE 59 - 
state_59_label:
   CLOSE_LLVM_CHAR(11);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_55_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   return 11;

// - STATE 60 - 
state_60_label:
   CLOSE_LLVM_CHAR(4);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 46)
      goto state_59_label;

   if (in_char >= 48 && in_char < 56)
      goto state_60_label;

   if (in_char >= 56 && in_char < 58)
      goto state_42_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 76)
      goto state_63_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   if (in_char == 108)
      goto state_63_label;

   return 4;

// - STATE 61 - 
state_61_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 43)
      goto state_98_label;

   if (in_char == 45)
      goto state_98_label;

   if (in_char >= 48 && in_char < 58)
      goto state_99_label;

   return c_idx_not_exist;

// - STATE 62 - 
state_62_label:
   CLOSE_LLVM_CHAR(10);
   return 10;

// - STATE 63 - 
state_63_label:
   CLOSE_LLVM_CHAR(7);
   return 7;

// - STATE 64 - 
state_64_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_100_label;

   if (in_char >= 65 && in_char < 71)
      goto state_100_label;

   if (in_char >= 97 && in_char < 103)
      goto state_100_label;

   return c_idx_not_exist;

// - STATE 65 - 
state_65_label:
   CLOSE_LLVM_CHAR(8);
   return 8;

// - STATE 66 - 
state_66_label:
   CLOSE_LLVM_CHAR(53);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 61)
      goto state_101_label;

   return 53;

// - STATE 67 - 
state_67_label:
   CLOSE_LLVM_CHAR(51);
   return 51;

// - STATE 68 - 
state_68_label:
   CLOSE_LLVM_CHAR(46);
   return 46;

// - STATE 69 - 
state_69_label:
   CLOSE_LLVM_CHAR(50);
   return 50;

// - STATE 70 - 
state_70_label:
   CLOSE_LLVM_CHAR(52);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 61)
      goto state_102_label;

   return 52;

// - STATE 71 - 
state_71_label:
   CLOSE_LLVM_CHAR(40);
   return 40;

// - STATE 72 - 
state_72_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_103_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 73 - 
state_73_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 110)
      goto state_26_label;

   if (in_char == 110)
      goto state_104_label;

   if (in_char >= 111 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 74 - 
state_74_label:
   CLOSE_LLVM_CHAR(25);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 25;

// - STATE 75 - 
state_75_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 115)
      goto state_26_label;

   if (in_char == 115)
      goto state_105_label;

   if (in_char >= 116 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 76 - 
state_76_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 50)
      goto state_26_label;

   if (in_char == 50)
      goto state_81_label;

   if (in_char >= 51 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 77 - 
state_77_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 52)
      goto state_26_label;

   if (in_char == 52)
      goto state_81_label;

   if (in_char >= 53 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 78 - 
state_78_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_81_label;

   if (in_char >= 55 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 79 - 
state_79_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 50)
      goto state_26_label;

   if (in_char == 50)
      goto state_81_label;

   if (in_char >= 51 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 80 - 
state_80_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 52)
      goto state_26_label;

   if (in_char == 52)
      goto state_81_label;

   if (in_char >= 53 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 81 - 
state_81_label:
   CLOSE_LLVM_CHAR(12);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 12;

// - STATE 82 - 
state_82_label:
   CLOSE_LLVM_CHAR(23);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 23;

// - STATE 83 - 
state_83_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 116)
      goto state_26_label;

   if (in_char == 116)
      goto state_106_label;

   if (in_char >= 117 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 84 - 
state_84_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_81_label;

   if (in_char >= 55 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 85 - 
state_85_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 50)
      goto state_26_label;

   if (in_char == 50)
      goto state_81_label;

   if (in_char >= 51 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 86 - 
state_86_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 52)
      goto state_26_label;

   if (in_char == 52)
      goto state_81_label;

   if (in_char >= 53 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 87 - 
state_87_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_107_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 88 - 
state_88_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 105)
      goto state_26_label;

   if (in_char == 105)
      goto state_108_label;

   if (in_char >= 106 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 89 - 
state_89_label:
   CLOSE_LLVM_CHAR(39);
   return 39;

// - STATE 90 - 
state_90_label:
   CLOSE_LLVM_CHAR(42);
   return 42;

// - STATE 91 - 
state_91_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 39)
      goto state_109_label;

   return c_idx_not_exist;

// - STATE 92 - 
state_92_label:
   CLOSE_LLVM_CHAR(0);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 39)
      goto state_109_label;

   return 0;

// - STATE 93 - 
state_93_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 39)
      goto state_110_label;

   if (in_char >= 48 && in_char < 56)
      goto state_111_label;

   return c_idx_not_exist;

// - STATE 94 - 
state_94_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_112_label;

   if (in_char >= 65 && in_char < 71)
      goto state_112_label;

   if (in_char >= 97 && in_char < 103)
      goto state_112_label;

   return c_idx_not_exist;

// - STATE 95 - 
state_95_label:
   CLOSE_LLVM_CHAR(0);
   return 0;

// - STATE 96 - 
state_96_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char < 47)
      goto state_56_label;

   if (in_char == 47)
      goto state_113_label;

   if (in_char >= 48 && in_char < 257)
      goto state_56_label;

   return c_idx_not_exist;

// - STATE 97 - 
state_97_label:
   CLOSE_LLVM_CHAR(68);
   return 68;

// - STATE 98 - 
state_98_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_99_label;

   return c_idx_not_exist;

// - STATE 99 - 
state_99_label:
   CLOSE_LLVM_CHAR(11);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_99_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 102)
      goto state_62_label;

   return 11;

// - STATE 100 - 
state_100_label:
   CLOSE_LLVM_CHAR(6);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_100_label;

   if (in_char >= 65 && in_char < 71)
      goto state_100_label;

   if (in_char == 76)
      goto state_114_label;

   if (in_char >= 97 && in_char < 103)
      goto state_100_label;

   if (in_char == 108)
      goto state_114_label;

   return 6;

// - STATE 101 - 
state_101_label:
   CLOSE_LLVM_CHAR(36);
   return 36;

// - STATE 102 - 
state_102_label:
   CLOSE_LLVM_CHAR(37);
   return 37;

// - STATE 103 - 
state_103_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char == 97)
      goto state_115_label;

   if (in_char >= 98 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 104 - 
state_104_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 116)
      goto state_26_label;

   if (in_char == 116)
      goto state_116_label;

   if (in_char >= 117 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 105 - 
state_105_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_117_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 106 - 
state_106_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 117)
      goto state_26_label;

   if (in_char == 117)
      goto state_118_label;

   if (in_char >= 118 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 107 - 
state_107_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char == 97)
      goto state_119_label;

   if (in_char >= 98 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 108 - 
state_108_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_120_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 109 - 
state_109_label:
   CLOSE_LLVM_CHAR(3);
   return 3;

// - STATE 110 - 
state_110_label:
   CLOSE_LLVM_CHAR(1);
   return 1;

// - STATE 111 - 
state_111_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 39)
      goto state_110_label;

   if (in_char >= 48 && in_char < 56)
      goto state_121_label;

   return c_idx_not_exist;

// - STATE 112 - 
state_112_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 39)
      goto state_122_label;

   if (in_char >= 48 && in_char < 58)
      goto state_123_label;

   if (in_char >= 65 && in_char < 71)
      goto state_123_label;

   if (in_char >= 97 && in_char < 103)
      goto state_123_label;

   return c_idx_not_exist;

// - STATE 113 - 
state_113_label:
   CLOSE_LLVM_CHAR(69);
   return 69;

// - STATE 114 - 
state_114_label:
   CLOSE_LLVM_CHAR(9);
   return 9;

// - STATE 115 - 
state_115_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 107)
      goto state_26_label;

   if (in_char == 107)
      goto state_124_label;

   if (in_char >= 108 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 116 - 
state_116_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 105)
      goto state_26_label;

   if (in_char == 105)
      goto state_125_label;

   if (in_char >= 106 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 117 - 
state_117_label:
   CLOSE_LLVM_CHAR(24);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 24;

// - STATE 118 - 
state_118_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 114)
      goto state_26_label;

   if (in_char == 114)
      goto state_126_label;

   if (in_char >= 115 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 119 - 
state_119_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 116)
      goto state_26_label;

   if (in_char == 116)
      goto state_127_label;

   if (in_char >= 117 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 120 - 
state_120_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_128_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 121 - 
state_121_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 39)
      goto state_110_label;

   return c_idx_not_exist;

// - STATE 122 - 
state_122_label:
   CLOSE_LLVM_CHAR(2);
   return 2;

// - STATE 123 - 
state_123_label:
   CLOSE_LLVM_CHAR(c_idx_not_exist);
   GET_LLVM_NEXT_CHAR();

   if (in_char == 39)
      goto state_122_label;

   return c_idx_not_exist;

// - STATE 124 - 
state_124_label:
   CLOSE_LLVM_CHAR(27);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 27;

// - STATE 125 - 
state_125_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 110)
      goto state_26_label;

   if (in_char == 110)
      goto state_129_label;

   if (in_char >= 111 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 126 - 
state_126_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 110)
      goto state_26_label;

   if (in_char == 110)
      goto state_130_label;

   if (in_char >= 111 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 127 - 
state_127_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 105)
      goto state_26_label;

   if (in_char == 105)
      goto state_131_label;

   if (in_char >= 106 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 128 - 
state_128_label:
   CLOSE_LLVM_CHAR(26);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 26;

// - STATE 129 - 
state_129_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 117)
      goto state_26_label;

   if (in_char == 117)
      goto state_132_label;

   if (in_char >= 118 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 130 - 
state_130_label:
   CLOSE_LLVM_CHAR(29);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 29;

// - STATE 131 - 
state_131_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_133_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 132 - 
state_132_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_134_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 133 - 
state_133_label:
   CLOSE_LLVM_CHAR(13);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_135_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 134 - 
state_134_label:
   CLOSE_LLVM_CHAR(28);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 28;

// - STATE 135 - 
state_135_label:
   CLOSE_LLVM_CHAR(22);
   GET_LLVM_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 22;

}/*}}}*/

bool llvm_parser_s::parse_source()
{/*{{{*/
  old_input_idx = 0;

  lalr_stack.clear();
  lalr_stack.push(0);

  unsigned input_idx = 0;
  unsigned ret_term = c_idx_not_exist;

  do
  {
    // - retrieve of next terminal symbol -
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;

      ret_term = recognize_terminal(input_idx);
      debug_message_5(fprintf(stderr,"llvm_parser: recognized terminal: %u\n",ret_term));

      // - PARSE ERROR unrecognized terminal -
      if (ret_term == c_idx_not_exist)
      {
        interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
        exception_s *new_exception = exception_s::throw_exception(it,c_error_LLVM_PARSER_UNRECOGNIZED_TERMINAL,0,(location_s *)it.blank_location);
        new_exception->params.push(old_input_idx);

        return false;
      }

      // - skip of _SKIP_ terminals -
      if (ret_term >= 66 && ret_term <= 69)
      {
        ret_term = c_idx_not_exist;
      }
    }

    // - retrieve of action from table of actions -
    unsigned parse_action = llvm_lalr_table[lalr_stack.last().lalr_state*c_llvm_terminal_plus_nonterminal_cnt + ret_term];

    // - PARSE ERROR wrong syntax -
    if (parse_action == c_idx_not_exist)
    {
        interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
        exception_s *new_exception = exception_s::throw_exception(it,c_error_LLVM_PARSER_SYNTAX_ERROR,0,(location_s *)it.blank_location);
        new_exception->params.push(old_input_idx);

        return false;
    }

    // - action SHIFT -
    if (parse_action < c_llvm_lalr_table_reduce_base)
    {

      if (ret_term == 70)
      {
        break;
      }

      // - insertion of state, and terminal position in source string -
      lalr_stack.push(parse_action,old_input_idx,input_idx);
      ret_term = c_idx_not_exist;
    }

    // - action REDUCE-
    else
    {
      parse_action -= c_llvm_lalr_table_reduce_base;

      // - call of function assigned to reduction -
      if (llvm_pa_callers[parse_action] != llvm_pa_null)
      {
        if (!llvm_pa_callers[parse_action](*this))
        {
          return false;
        }
      }

      // - remove of rule body from lalr_stack -
      lalr_stack.used -= llvm_rule_body_lengths[parse_action];

      // - insert of new automat state to stack -
      unsigned goto_val = llvm_lalr_table[lalr_stack.last().lalr_state*c_llvm_terminal_plus_nonterminal_cnt + llvm_rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(1);

  return true;
}/*}}}*/

