//
//  main.c
//  1-0
//
//  Created by liu yao-chun on 13/1/22.
//  Copyright (c) 2013年 liu yao-chun. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
	char firststring[100]="Hello, World!!";
	int i=0;
	while (firststring[i]!='\0')
	{
			i++;
	}
	printf("%s, %d\n",firststring,i);
	
	
	// insert code here...
	printf("Hello, World!\n");
    return 0;
}

