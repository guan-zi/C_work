#include <stdio.h>

int main()
{
	int lists[4][50] = {{1,2,3,'\0'},{4,5,6,'\0'},{7,8,'\0'},{10,11,12,'\0'}};
	


}


int combM(int lists[][maxSize], int lens[], int m)
{
	int flag;
	for (int i = 1;i<m; ++i)
	{
		flag = comb(lists[0], lens[0], lists[i], lens[i]);
		if(flag==-1)
			break;
	}
	return flag;
}
