double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size == 0 && nums2Size == 0)
    {
        return 0.0;
    }
    bool needDivide = (nums1Size + nums2Size) % 2 == 0;
    int end = (nums1Size + nums2Size) / 2;
    end = needDivide ? end - 1 : end;

    int nums1Length=0, nums2Length = 0;

    for (int i = 0; i < end; i++)
    {
        if (nums1Length < nums1Size && nums2Length < nums2Size)
        {
            if (*(nums1 + nums1Length) > *(nums2 + nums2Length))
            {
                nums2Length++;
            }
            else
            {
                nums1Length++;
            }
        }
        else if (nums1Length == nums1Size)
        {
            nums2Length++;
        }
        else if (nums2Length == nums2Size)
        {
            nums1Length++;
        }
    }

    // we need to find the next bigger number and divide the sum of them by 2
    if (nums1Length < nums1Size && nums2Length < nums2Size)
    {
        for (int i = 0; i < nums1Length; i++)
        {
            nums1++;
        }
        for (int i = 0; i < nums2Length; i++)
        {
            nums2++;
        }
        if (!needDivide)
        {
            return *nums1 > *nums2 ? *nums2 : *nums1;
        }
        else
        {
            if (*nums1 > *nums2)
            {
                if (nums2Length == nums2Size - 1)
                { // reach the end of arr nums2
                    return (*nums1 + *nums2) / 2.0;
                }
                else
                {
                    if (*(nums2 + 1) > *nums1)
                    {
                        return (*nums1 + *nums2) / 2.0;
                    }
                    else
                    {
                        return (*nums2 + *(nums2 + 1)) / 2.0;
                    }
                }
            }
            else
            {
                if (nums1Length == nums1Size - 1)
                { // reach the end of arr nums1
                    return (*nums1 + *nums2) / 2.0;
                }
                else
                {
                    if (*(nums1 + 1) > *(nums2))
                    {
                        return (*nums2 + *nums1) / 2.0;
                    }
                    else
                    {
                        return (*nums1 + *(nums1 + 1)) / 2.0;
                    }
                }
            }
        }
    }
    else if (nums1Length == nums1Size)
    {
        for (int i = 0; i < nums2Length; i++)
        {
            nums2++; 13815248340
        }
        if (!needDivide)
        {
            return *nums2;
        }
        else
        {
            return (*nums2 + *(nums2 + 1)) / 2.0;
        }
    }
    else if (nums2Length == nums2Size)
    {
        for (int i = 0; i < nums1Length; i++)
        {
            nums1++;
        }
        if (!needDivide)
        {
            return *nums1;
        }
        else
        {
            return (*nums1 + *(nums1 + 1)) / 2.0;
        }
    }

    return 0.0;
}
