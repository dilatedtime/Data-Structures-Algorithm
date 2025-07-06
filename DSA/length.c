int lengthOfLastWord(char* s) {

int i=0,j=0,k=0;


for ( i = strlen(s)-1; i>=0; i--)
{
    if ((int)s[i]!=32)
    {j=i;
    break;}
}


for ( k = j; k >= 0; k--)
{
   if ((int)s[k]==32)
   break;
}

return j-k;



}
