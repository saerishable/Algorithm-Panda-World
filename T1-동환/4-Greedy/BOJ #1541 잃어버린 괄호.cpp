#include <stdio.h>

int main(){
	int number[25] = {0}; # 
	
	bool flag = 1;
	
	int sum = 0;
	
	/* 
	
	���� ����: ���õǴ� ������ ������ ������ �ľ��� ex) 5+6-7 -> 5, 6, -7
	������ �����ϴ� ���, �ش� �κ� ���ʹ� ���Ŀ� �����ϴ� ���� ��ȣ�� ���� �� �ִ�
	-> �׷��� ������ ������ ������ ���ڴ� ��� ���񰪿� -�� ���� ������ ����� ������. 
	
	*/ 
	
	for(int i = 0; i < 25; i++){
		scanf("%d", &number[i]);
		if(flag == 1 && number[i] < 0) flag = 0;  
		else if(flag == 0 && number[i] > 0) number[i] *= -1; // ������ ������ ������ ��� ����. 
		
		sum += number[i];
	}
	
	printf("%d", sum);
	return 0;
}
