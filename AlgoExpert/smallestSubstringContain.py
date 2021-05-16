# O(p+m) space and time
def smallestSubstringContain(main, patt):
    freqPattern = {}
    freqMain = {}
    for ch in patt:
        if ch in freqPattern.keys():
            freqPattern[ch]+=1
        else:
            freqMain[ch] = 0
            freqPattern[ch]=1
    start, end = 0, float("inf")
    left, right = 0, 0
    unique_count = 0
    while left < len(main) and right < len(main):
        while left < len(main) and main[left] not in freqMain.keys():
            left+=1
        while right < len(main) and main[right] not in freqMain.keys():
            right+=1
        while unique_count < len(freqMain) and right < len(main):
            #print(freqMain, left, right)
            if main[right] in freqPattern.keys():
                freqMain[main[right]] += 1
                if freqMain[main[right]] == freqPattern[main[right]]:
                    unique_count+=1
            right+=1
        #print(left, right, unique_count, freqMain)
        if unique_count == len(freqMain) and (end+1 - start) > (right- left):
            start, end = left, right-1
        if left < len(main) and main[left] in freqPattern.keys():
            freqMain[main[left]] -= 1
            if freqMain[main[left]] != freqPattern[main[left]]:
                unique_count -= 1
            left+=1
    return start, end

print(smallestSubstringContain("abcd$ef$axb$c$", "$b"))

# 0 1 2 3 4 5 6 7 8 9 10 11 12 13
# a b c d $ e f $ a x b   $  c #
#         l     r
# $2 b0                     
