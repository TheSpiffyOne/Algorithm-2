from itertools import product

def lpt_schedule(num_machines, jobs):
    # сортируем работы по убыванию (LPT)
    jobs_sorted = sorted(jobs, reverse=True)
    loads = [0] * num_machines
    assignment = [[] for _ in range(num_machines)]
    for job in jobs_sorted:
        # найти машину с минимальной текущей загрузкой (жадный выбор)
        i = loads.index(min(loads))
        assignment[i].append(job)
        loads[i] += job
    makespan = max(loads) if loads else 0
    return assignment, loads, makespan

def optimal_schedule_bruteforce(num_machines, jobs, cutoff_states=200_000):
    # сравнение с оптимальным только если пространство перебора невелико
    total_assignments = num_machines ** len(jobs)
    if total_assignments > cutoff_states:
        return None  # слишком большой перебор, отменяем
    best_makespan = None
    best_assign = None
    # перебираем все возможные распределения работ по машинам
    for assign in product(range(num_machines), repeat=len(jobs)):
        loads = [0]*num_machines
        for j_idx, m in enumerate(assign):
            loads[m] += jobs[j_idx]
        msp = max(loads)
        if best_makespan is None or msp < best_makespan:
            best_makespan = msp
            best_assign = assign
    # преобразуем best_assign в удобный вид
    assignment = [[] for _ in range(num_machines)]
    for j_idx, m in enumerate(best_assign):
        assignment[m].append(jobs[j_idx])
    loads = [sum(a) for a in assignment]
    return assignment, loads, best_makespan

if __name__ == "__main__":
    # Вручную вводим данные
    num_machines = int(input("Введите число машин (n): ").strip())
    jobs_str = input("Введите длительности работ через запятую или пробел: ").strip()
    # парсим список длительностей
    if "," in jobs_str:
        jobs = [int(x) for x in jobs_str.split(",") if x.strip()]
    else:
        jobs = [int(x) for x in jobs_str.split() if x.strip()]

    # жадный LPT
    g_assign, g_loads, g_makespan = lpt_schedule(num_machines, jobs)
    print("\nЖадный (LPT) результат:")
    for i, a in enumerate(g_assign):
        print(f" Машина {i}: работы {a}, суммарно {g_loads[i]}")
    print(" Makespan (жадный):", g_makespan)

    # если разумный размер — пробуем полный перебор для оптимума
    opt = optimal_schedule_bruteforce(num_machines, jobs)
    if opt is None:
        print("\nПолный перебор для поиска оптимума пропущен (пространство слишком велико).")
    else:
        o_assign, o_loads, o_makespan = opt
        print("\nОптимальное (полный перебор):")
        for i, a in enumerate(o_assign):
            print(f" Машина {i}: работы {a}, суммарно {o_loads[i]}")
        print(" Makespan (оптимум):", o_makespan)
        print("\nСравнение: жадный / оптимум ->", g_makespan, "/", o_makespan)
