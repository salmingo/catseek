/*
 Name        : catseek.cpp
 Author      : Xiaomeng Lu
 Version     : 0.1
 Copyright   : SVOM@NAOC, CAS
 Description : 搜索星表, 输出复合条件的参考星
 - 搜索UCAC4星表, 若找到则输出信息; 未找到继续
 - 搜索Tycho2星表, 若找到则输出信息
 */

#include <stdio.h>
#include <string>
#include "ATimeSpace.h"
#include "ACatTycho2.h"
#include "ACatUCAC4.h"

using namespace std;
using namespace AstroUtil;

/*
 * 命令行输入参数:
 * <1> 赤经. 角度
 * <2> 赤纬. 角度
 * <3> 半径, 量纲: 角分. 缺省时为1
 */
int main(int argc, char **argv) {
	if (argc < 3) {
		printf("%s\n", string('*', 60).c_str());
		printf("Usage:\n");
		printf("\t catseek ra dec [radius=1]\n");
		printf("%s\n", string('*', 60).c_str());
		exit(-1);
	}

	double ra0, dec0, radius(1.0);
	double ra, dec;
	ACatUCAC4 ucac4;
	ACatTycho2 tycho2;
	ATimeSpace ats;
	int n, i;

	ucac4.SetPathRoot("/Users/lxm/Catalogue/UCAC4");
	tycho2.SetPathRoot("/Users/lxm/catalogue/tycho2/tycho2.dat");

	ra0 = atof(argv[1]);
	dec0 = atof(argv[2]);
	if (argc == 4)
		radius = atof(argv[3]);

	if (ucac4.FindStar(ra0, dec0, radius)) {
		ptr_ucac4_elem stars, star;

		printf("from UCAC4:\n");
		stars = ucac4.GetResult(n);
		for (i = 0, star = stars; i < n; ++i, ++star) {
			ra = (double) star->ra / MILLISEC;
			dec = (double) star->spd / MILLISEC - 90.0;
			printf("[%4d] %10.6f %10.6f %8.1f %8.1f %6.3f %6.3f\n", i + 1, ra,
					dec, star->pmrac * 0.1, star->pmdc * 0.1,
					star->apasm[1] * 0.001, star->apasm[3] * 0.001);
		}
	}
	else if (tycho2.FindStar(ra0, dec0, radius)) {
		ptr_tycho2_elem stars, star;

		printf("from Tycho2:\n");
		stars = tycho2.GetResult(n);
		for (i = 0, star = stars; i < n; ++i, ++star) {
			ra = (double) star->ra / MILLISEC / 15;
			dec = (double) star->spd / MILLISEC - 90.0;

			printf("[%4d] %10.6f %10.6f %8.1f %8.1f %6.3f %6.3f\n", i + 1, ra,
					dec, star->pmrac * 0.1, star->pmdc * 0.1,
					star->apasm[0] * 0.001, star->apasm[1] * 0.001);
		}
	}
	else
		printf("!!! not found !!!\n");

	return 0;
}
