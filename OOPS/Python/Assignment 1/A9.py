student_names = ['Lisa', 'Rose', 'Jennie', 'Jisoo']
student_marks = ['78', '54', '99', '98']
student_subjects = ['OOPS', 'DLD', 'CO', 'DS & Algo']

def main():
	tuples = list(zip(student_names, student_subjects, student_marks))
	maximum = sorted(tuples, key=lambda x: x[2], reverse=True)[0]
	print(maximum)

if __name__=="__main__":
	main()

