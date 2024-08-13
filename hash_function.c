#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

/* Hashing function used 
   floor(abs(x*sin((l/k/n)*x))
   where 
   l is the sum of all the unique letters in the word
   k is the permutation of no of unique letters
   n is the positon of the letter
*/

//Function for creating sum of ASCII codes of the word
int sumofchar(int n,char arr[n])
{   
    int charint[n];
    int lm=0;
    for (int i = 0; i < n; i++)
    {
        charint[i]=(int)arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        lm=lm+charint[i];
    }
    return lm;
}

//Function to get the number of unique letters in the word
int count(char arr[],char n)
{
    int m=1;
    char countarr[n];
    for (int k = 0; k < n; k++)
    {
        countarr[k]=arr[k];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i]==countarr[j])
        {
            countarr[j]='*';
        }
        }   
    }   
    
    for (int i = 1; i <= n; i++)
    {
        if(countarr[i]=='*'){
        }
        else {
            m++;
        }
    }    
    return m;
}

//Function to create permutation
int permutation(int m){
    int k=0;
    for (int i = 1; i <= m; i++)
    {
        k=k+i;
    }
    return k;
}

int main()
{
    int n,l,k,m;
    char str[n];
    printf("Enter the size of the word : ");
    scanf("%d",&n);
    printf("Enter the String : ");
    scanf("%s",str);
    m=count(str,n);
    l=sumofchar(n,str)/m;
    k=permutation(m);
    int output[n];
    for (int i = 0; i < n; i++)
    {
        output[i]=floor(abs((int)str[i]*sin((l*k/(i+1))*(int)str[i])));
        output[i]=(int)output[i];
        if ((output[i]<=25)&&(output[i]>=0))
        {
            output[i]=output[i]+65;
        }
        else if ((output[i]<=31)&&(output[i]>=26))
        {
            output[i]=output[i]+45;
        }  
        else if ((output[i]<=57)&&(output[i]>=32))
        {
            output[i]=output[i]+33;
        }
        else if ((output[i]<=64)&&(output[i]>=58))
        {
            output[i]=output[i]+8;
        }
        else if ((output[i]<=96)&&(output[i]>=91))
        {
            output[i]=output[i]+8;
        }  
    }
    printf("Encrypted word is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%c",(char)output[i]);
    }
    printf("\n");

return 0;

}
