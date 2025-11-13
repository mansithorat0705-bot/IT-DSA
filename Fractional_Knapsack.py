profits=[60,70,80]
weights=[10,20,30]
capacity=50

ratio=[]
for i in range(len(profits)):
    ratio.append(profits[i] / weights[i])
    
items=list(zip(profits,weights,ratio))
items.sort(key=lambda x: x[2], reverse=True)

total_profit=0
current_weight=0

for profit,weight,r in items:
   if current_weight + weight <= capacity:
       current_weight+=weight
       total_profit+=profit
   else:
       remain=capacity-current_weight
       total_profit += profit*(remain/weight)
       break
print("Maximum profit=",total_profit)   