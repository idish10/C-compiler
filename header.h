#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define SUCCESSFUL -1313
#define LABEL_MAX_SIZE 32
#define LINE_SIZE 80
#define KEEP_RUNNING 1212
#define DEFAULT -1211

struct image_data{
char symbol_as_operand[LABEL_MAX_SIZE];
int op_code;
long address;
int * code;
int size_of_code;
int status;
int file_number;
};




struct symbols{
int file_number;
char name[LABEL_MAX_SIZE];
char symbol_type[9];
char symbol_status[9];
long address;
int ENTRY_FLAG;
};


typedef enum {CODE,DATA,WITHOUT} type;
typedef enum {EXTERNAL,ENTRY,NONE} source;
typedef enum {F,T} boolean;


typedef struct symbols * ptr_symbol;
typedef struct symbols symbol;
typedef struct image_data * ptr_img_data;
typedef struct image_data img_data;

void making_output_files(ptr_symbol ,ptr_img_data ,int ,unsigned int ,unsigned int ,char ** );
int binar_to_hex(int * , int ,int );
int complete_data_table(ptr_symbol ,ptr_img_data ,unsigned int ,unsigned int );
int * number_to_binar(long ,int );
int checking_entry_symbol_for_extern(ptr_symbol , unsigned int  );
int * digit_to_binar(int ,int ,unsigned long);
int * asciz_to_binar(char ,unsigned long );
ptr_img_data data_to_binar(int ,long * ,unsigned int * , ptr_img_data , int * , unsigned int * ,char * ,boolean * , unsigned long *, int );
char * reading_data_asciz(char *, boolean * ,unsigned long *, int , int ,unsigned int * );
int * reading_data_numbers(char * , boolean * , unsigned long *, int, int, unsigned int * );
ptr_symbol entry_extern(char *  ,char *,int ,ptr_symbol , unsigned int * , boolean * , int ,unsigned long * ,char ** , char **);
int * I_coditional(char *, boolean *, unsigned long *, int , int,char *);
int * checking_arguments_I_aritmathic(char * ,boolean *,unsigned long *, int , int );
int * checking_arguments_jmp(char * , boolean * , unsigned long *, int , int ,char *, int * );
int checking_arguments_la_and_call(char * ,boolean * ,unsigned long * , int  ,char * );
int * decimal_to_binar_R(int ,int ,int ,int ,int );
int * decimal_to_binar_I(int immed,int rt, int rs , int opcode );
int * decimal_to_binar_J(int address,int reg,int opcode);
ptr_symbol add_symbol(char *,  int ,int ,unsigned int  * ,ptr_symbol ,boolean * , unsigned long * ,char ** , char **  ,  long * , long * , type , int );
int * checking_arguments_R(char * ,boolean * ,unsigned long * , int , int );
int operation_type(char * ,int ,int ,char ** ,char **,type);
ptr_img_data to_binar(char *  , int * ,int ,long * ,unsigned int * ,ptr_img_data  ,boolean * ,unsigned long * ,unsigned int * ,ptr_symbol ,int );
