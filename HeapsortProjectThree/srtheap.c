// gcc -std=c99 -DRAND -DPRNT -DTYPE=(float | double) -D(BUBB | HEAP | INSR | MERG) *.c

#include <stdio.h>

void main()
{
int heapArray[10], length, i, j, c, rootelement, tempArray;

printf("\n Enter length of elements :");
scanf("%d", &length);
printf("\n Enter the lengths : ");
for (i = 0; i < length; i++)
scanf("%d", &heapArray[i]);
for (i = 1; i < length; i++)
{
c = i;
do
{
rootelement = (c - 1) / 2; 
if (heapArray[rootelement] < heapArray[c]) /* to create MAX heapArray array */
{
tempArray = heapArray[rootelement];
heapArray[rootelement] = heapArray[c];
heapArray[c] = tempArray;
}
c = rootelement;
} while (c != 0);
}

printf("heapArray array\t\t:");
for (i = 0; i < length; i++)
printf("%d\t ", heapArray[i]);
for (j = length - 1; j >= 0; j--)
{
tempArray = heapArray[0];
heapArray[0] = heapArray[j]; /* swap max element with rightmost leaf element */
heapArray[j] = tempArray;
rootelement = 0;
do 
{
c = 2 * rootelement + 1; /* left lengthde of rootelement element */
if ((heapArray[c] < heapArray[c + 1]) && c < j-1)
c++;
if (heapArray[rootelement]<heapArray[c] && c<j) /* again rearrange to max heapArray array */
{
tempArray = heapArray[rootelement];
heapArray[rootelement] = heapArray[c];
heapArray[c] = tempArray;
}
rootelement = c;
} while (c < j);
} 
printf("\nThe sorted array is\t:");
for (i = 0; i < length; i++)
printf("%d\t", heapArray[i]);

}