from nltk import tokenize

txt = open("text.txt")
data = txt.read()
l = tokenize.sent_tokenize(data)
list_of_length = []

for sentense in l:
    # print(len(tokenize.word_tokenize(sentense)))
    # print(tokenize.word_tokenize(sentense))
    list_of_length.append(len(tokenize.word_tokenize(sentense)))

list_of_length.sort()

output = open("output.txt", "w")
for sentense in l:
    # print(type(len(tokenize.word_tokenize(sentense))))
    if (len(tokenize.word_tokenize(sentense)) in list_of_length[-5:]):
        for i in sentense:
            output.write(i)
        output.write("\n\n")
