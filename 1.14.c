int i = 0;
int* ans = (int*)malloc(numsSize * 2 * sizeof(int));
for (i = 0; i < numsSize; i++)
{
    ans[i] = nums[i];
    ans[i + numsSize] = nums[i];
}
*returnSize = 2 * numsSize;
return ans;