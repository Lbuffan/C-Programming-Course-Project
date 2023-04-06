#include "public.h"
#include "build.h"

/*
FUNCTION:Build_State
DESCRIPTION:生成state.dat
INPUT:NO
RETURN:NO
*/
void Build_State()	//生成state.dat
{
	STATE* s=NULL;
	FILE* fp;
	int i;
	if((fp=fopen("C:\\TRY\\TEXT\\state.dat","wb+"))==NULL)
	{
		printf("\nError on open file state.dat!");
		delay(3000);
		exit(1);
	}
	for(i=0;i<1000;i++)
	{
		s->number=i+1;
		s->patient=0;
		s->contact=0;
		s->deal=0;
		s->find=0;
		fwrite(s,sizeof(STATE),1,fp);
	}
}