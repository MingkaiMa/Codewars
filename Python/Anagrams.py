def get_info(word):
    a = set(word)
    dic = {}
    for i in a:
        dic[i] = word.count(i)

    return dic


def anagrams(word, words):
    R = []
    target_dic = get_info(word)
    for w in words:
        temp_dic = get_info(w)
        if temp_dic == target_dic:
            R.append(w)

    return R