#include "../src/checkExpression.c"
int main(int argc,char **args){
	if(checkExpression()) printf("表达式正确\n");
	else printf("表达式不正确\n");
	return 0;
}
