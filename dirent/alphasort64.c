/* Copyright (C) 1992-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#define alphasort __no_alphasort_decl
#include <dirent.h>
#undef alphasort
#include <string.h>
/*
	comment by Clark
	::   
	c语言strcoll()函数应用实例根据环境变量LC_COLLATE来比较字符串。函数引入的头文件：#include <string.h>
	定义strcoll()函数：int strcoll(const char *s1, const char *s2);

	strcoll()函数介绍：strcoll()会依环境变量LC_COLLATE 所指定的文字排列次序来比较s1 和s2 字符串。

	strcoll()函数返回值：若参数s1 和s2 字符串相同则返回0。s1 若大于s2 则返回大于0 的值，s1 若小于s2 则返回小于0 的值。

	附加说明：若 LC_COLLATE 为”POSIX”或”C”，则strcoll()与strcmp()作用完全相同。

	::
	2021-4-9
*/ 
int
alphasort64 (const struct dirent64 **a, const struct dirent64 **b)
{
  return strcoll ((*a)->d_name, (*b)->d_name);
}

#if _DIRENT_MATCHES_DIRENT64
weak_alias (alphasort64, alphasort)
#endif
