pet1 = {"kaixin" : ['cat', 'tanjiangcheng']}
pet2 = {'xinxin' : ['dog', 'liushiming']}
pet3 = {'mingming': ['pig', 'zhangsan']}

pets = [pet1, pet2, pet3]

for pet in pets:
    for name, detail in pet.items() :
        print(f'\nName: {name}')
        print(f'\ttype: {detail[0]}')
        print(f'\tmaster: {detail[1]}')


    
