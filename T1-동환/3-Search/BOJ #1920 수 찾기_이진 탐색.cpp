#include <stdio.h>
#include <stdlib.h>

// ����Ž�� - �� ã�� 

int compare(const void* a, const void* b)
{
    if(*(int*)a > *(int*)b)
        return 1;
    else if(*(int*)a == *(int*)b)
        return 0;
    else return -1;
}

int binarySearch(int* array, int size, int wtf){ // �迭, ũ��, ã�ƾ��� ��.
    int mid = 0;
    int start = 0;
    int end = size - 1;
    
    while(start <= end){
        mid = (start + end) / 2;
        if(array[mid] == wtf) return 1;
        else if(array[mid] > wtf) end = mid -1;
        else if(array[mid] < wtf) start = mid + 1;
    }
    return 0;
}

int main(){
    int list = 0;
    scanf("%d", &list);
 
    int origin[list] ={0};
    for(int i = 0; i < list; i++){
        scanf("%d", &origin[i]);
    }
    
    
    int test = 0;
    scanf("%d", &test);
 
    int find[test] = {0};
    for(int i = 0; i <test; i++){
        scanf("%d", &find[i]);
    }
    qsort(origin, list, sizeof(int), compare); // �������� ����, ���� Ž���� ������ �迭�� ������.
    
    for(int i = 0; i < test; i++){
        printf("%d\n", binarySearch(origin, list, find[i])); // Ž�� ����
    }
    
    return 0;
}
