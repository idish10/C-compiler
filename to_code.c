#include "header.h"
int binar_to_hex(int * code, int index_max,int index_min){
int index=index_min;
int num=0;
int temp;
do{
temp=code[index];
num=(num<<1)|temp;
index++;
}while(index<=index_max);
return num;
}


int * number_to_binar(long value,int size){
long k=0;
int count=0;
int temp_size;
int * temp=(int*)calloc(size,sizeof(int));
temp_size-=1;


				if (!temp){
		printf("cannot allocate memory");
				return NULL;}


for(temp_size=size-1; temp_size>=0 ; temp_size--)
{
k=value>>temp_size;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}
return temp;
}




int * asciz_to_binar(char word,unsigned long COUNTER_LINES){
int size=7;
int temp_number=word;
int * temp=(int*)calloc(size+1,sizeof(int));


				if (!temp){
		printf("cannot allocate memory\nLINE NUMBER:%lu",COUNTER_LINES);
				return NULL;}

if(word=='\0'){
	for(size; size>=0 ; size--)
		temp[size]=0;}
else{
int k;
int count=0;

for(size; size>=0 ; size--)
{
k=temp_number>>size;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}}
return temp;
}


int * digit_to_binar(int value,int size,unsigned long COUNTER_LINES){
int k;
int count=0;
int * temp=(int*)calloc(size,sizeof(int));
size=size-1;

				if (!temp){
		printf("cannot allocate memory\nLINE NUMBER:%lu",COUNTER_LINES);
				return NULL;}




for(size; size>=0 ; size--)
{
k=value>>size;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}
return temp;
}





int * decimal_to_binar_R(int funct,int rd,int rt,int rs,int opcode){
int k,c;
int count=0;
int * temp=(int*)calloc(32,sizeof(int));
				if (!temp){
			printf("cannot allocate memory");
				return NULL;}



for(c=5; c>=0 ; c--)
{
k=opcode>>c;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}
for(c=4; c>=0 ; c--)
{
k=rs>>c;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}


for(c=4; c>=0 ; c--)
{
k=rt>>c;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}


for(c=4; c>=0 ; c--)
{
k=rd>>c;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}

for(c=4; c>=0 ; c--)
{
k=funct>>c;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}
while(count!=32){
temp[count]=0;
count++;
}
return temp;
}









int * decimal_to_binar_I(int immed,int rt, int rs , int opcode ){
int k,c;
int count=0;
int * temp=(int*)calloc(32,sizeof(int));
				if (!temp){
			printf("cannot allocate memory");
				return NULL;}

for(c=5; c>=0 ; c--)
{
k=opcode>>c;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}


for(c=4; c>=0 ; c--)
{
k=rs>>c;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}


for(c=4; c>=0 ; c--)
{
k=rt>>c;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}

for(c=15; c>=0 ; c--)
{
k=immed>>c;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}

return temp;
}




int * decimal_to_binar_J(int address,int reg,int opcode){
int k,c;
int count=0;
int * temp=(int*)calloc(32,sizeof(int));
				if (!temp){
			printf("cannot allocate memory");
				return NULL;}




for(c=5; c>=0 ; c--)
{
k=opcode>>c;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}

temp[count]=reg;
count++;

for(c=24; c>=0 ; c--)
{
k=address>>c;
if(k&1)
temp[count]=1;
else
temp[count]=0;
count++;
}
return temp;
}
	
