# file = open("a.txt","r")
# file = open("b.txt","r")
# file = open("c.txt","r")
file = open("d.txt","r")
# file = open("e.txt","r")
# file = open("f.txt","r")

d, i, s, v, f = [int(num) for num in file.readlines(1)[0][:-1].split()]
streetEnd = {}
street_time = {}
car_path = []
graph = {inter:[] for inter in range(i)}
street_car_queue = {}

for _ in range(s):
    graph_info = file.readlines(1)[0][:-1].split()
    streetEnd[graph_info[2]] = int(graph_info[1])
    street_time[graph_info[2]] = int(graph_info[-1])
    street_car_queue[graph_info[2]] = []
    graph[int(graph_info[0])].append(int(graph_info[1]))

for _ in range(v):
    streets = file.readlines(1)[0][:-1].split()[1:]
    street_car_queue[streets[0]].append(_)
    car_path.append(streets)

file.close()

def time_for_fav_car(car_path, street_car_queue, street_time):
    resInd = -1
    calTime = 0
    minTime = float('inf')
    greenLight = '---'
    for path, ind in zip(car_path, range(len(car_path))):
        if(ind != street_car_queue[path[0]][0]):
            continue
        for strt in path[1:]:
            calTime+=street_time[strt]
            calTime+=len(street_car_queue[strt])
        if(calTime < minTime):
            resInd = ind
            minTime = calTime
            greenLight = path[0]
        calTime = 0
    return [resInd, minTime, greenLight]

green_street_time = {}

green_choice = time_for_fav_car(car_path, street_car_queue, street_time)
# num_retry = 20000
while(green_choice[1] <= d):
    if(len(car_path[green_choice[0]]) >= 2):
        if(streetEnd[car_path[green_choice[0]][1]] in graph[streetEnd[green_choice[2]]]):
            street_car_queue[car_path[green_choice[0]][1]].append(green_choice[0])
            street_car_queue[green_choice[2]].pop(0)
            car_path[green_choice[0]].pop(0)
            if(green_choice[2] in green_street_time.keys()):
                green_street_time[green_choice[2]] += 1
            else:
                green_street_time[green_choice[2]] = 1
        else:
            car_path.pop(green_choice[0])
    else:
        car_path.pop(green_choice[0])
    green_choice = time_for_fav_car(car_path, street_car_queue, street_time)
    # num_retry-=1

schedule = {}
for strt in green_street_time.keys():
    if(streetEnd[strt] not in schedule.keys()):
        schedule[streetEnd[strt]] = [[strt,  green_street_time[strt]]]
    else:
        schedule[streetEnd[strt]].append([strt,  green_street_time[strt]])

op_file = open("output_d.txt", "a")
op_file.write(str(len(schedule)))
op_file.write("\n")
for inter in schedule.keys():
    op_file.write(str(inter))
    op_file.write("\n")
    op_file.write(str(len(schedule[inter])))
    op_file.write("\n")
    for lst in schedule[inter]:
        op_file.write(lst[0])
        op_file.write(" ")
        op_file.write(str(lst[1]))
        op_file.write("\n")
op_file.close()