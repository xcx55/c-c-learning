#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include  <stdio.h>
#include  <string.h>
struct student {
	long  sno;
	char  name[10];
	float  score[3];
};
void fun(struct student* b)
{
	/**********found**********/
	b->sno = 10004;
	/**********found**********/
	strcpy(b->name, "LiJie");

}
main()
{
	struct student  t = { 10002,"ZhangQi", 93, 85, 87 };
	int  i;
	printf("\n\nThe original data :\n");
	printf("\nNo: %ld  Name: %s\nScores:  ", t.sno, t.name);
	for (i = 0; i < 3; i++)  printf("%6.2f ", t.score[i]);
	printf("\n");
	/**********found**********/
	fun(&t);
	printf("\nThe data after modified :\n");
	printf("\nNo: %ld  Name: %s\nScores:  ", t.sno, t.name);
	for (i = 0; i < 3; i++)  printf("%6.2f ", t.score[i]);
	printf("\n");
	getchar();
}
//void fun(char* ss)
//{
//    char* pa = ss;
//    ss++;
//    while (*ss) {
//        if ((*ss)>=97&&(*ss)<=122) {
//            (*ss) -= 32;
//        }
//        if (*(ss+1)=='\0') {
//            return;
//
//    }
//        ss += 2;
//    }
//
//}
//int main() {
//    char pa[] = "abccccaz";
//    fun(pa);
//
//    return 0;
//}