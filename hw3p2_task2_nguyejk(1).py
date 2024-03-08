import random
random.seed(1)
questions_file = open('TeamQuestion.txt', 'r')
questions = questions_file.readlines()
questions_file.close()

num_questions = int(input("How Many questions to store in new file? "))
selected = 0
output_file = open('QuestionsToAsk.txt', 'w')

while selected < num_questions:
    question = random.choice(questions).strip()
    print(question)
    if input("Keep this question? Enter (y or n): ").lower() == 'y':
        output_file.write(question + '\n')
        selected += 1

output_file.close()
