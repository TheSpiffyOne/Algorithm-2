#include <bits/stdc++.h>
using namespace std;

// Вывод распределения в удобном виде
void print_solution(const vector<vector<pair<int,int>>>& machine_jobs, const vector<int>& loads) {
    int m = machine_jobs.size();
    for (int i = 0; i < m; ++i) {
        cout << "Machine " << i+1 << " (load=" << loads[i] << "): ";
        for (auto &p : machine_jobs[i]) {
            cout << "[job" << p.first << "=" << p.second << "] ";
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; // число машин
    cout << "Enter number of machines: ";
    if (!(cin >> n) || n <= 0) return 0;

    int m; // число работ
    cout << "Enter number of jobs: ";
    if (!(cin >> m) || m <= 0) return 0;

    vector<int> jobs(m);
    cout << "Enter " << m << " job durations (space separated or newline):\n";
    for (int i = 0; i < m; ++i) cin >> jobs[i];

    // ----- Жадный алгоритм LPT -----
    // Сортируем работы по убыванию длительности, сохраняя исходные индексы
    vector<pair<int,int>> sorted;
    sorted.reserve(m);
    for (int i = 0; i < m; ++i) sorted.emplace_back(i, jobs[i]);
    sort(sorted.begin(), sorted.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.second > b.second; // по убыванию длительности
    });

    // мин-куча по (load, machine_index)
    vector<int> loads(n, 0);
    vector<vector<pair<int,int>>> machine_jobs(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int i = 0; i < n; ++i) pq.emplace(0, i);

    for (auto &pr : sorted) {
        int job_idx = pr.first;
        int dur = pr.second;
        auto cur = pq.top(); pq.pop();
        int cur_load = cur.first;
        int machine = cur.second;
        // назначаем работу на машину с минимальной текущей загрузкой
        loads[machine] += dur;
        machine_jobs[machine].emplace_back(job_idx+1, dur); // job indices с 1
        pq.emplace(loads[machine], machine);
    }

    cout << "\nGreedy LPT solution:\n";
    print_solution(machine_jobs, loads);
    int makespan_greedy = *max_element(loads.begin(), loads.end());
    cout << "Greedy makespan = " << makespan_greedy << "\n\n";

    // ----- Перебор для точного (оптимального) решения при маленьких m -----
    // Ограничим перебор, чтобы не взорвать время: если n^m > 5e6, пропустим.
    // (для вашего примера m=10, n=3 => 3^10 = 59049 -> OK)
    double try_count = pow((double)max(1,n), (double)m);
    if (try_count <= 5e6) {
        long long best_makespan = LLONG_MAX;
        vector<int> best_assign(m, -1);
        // рекурсивный перебор (backtracking)
        vector<int> cur_loads(n,0);
        function<void(int)> dfs = [&](int pos) {
            if (pos == m) {
                int cur_max = 0;
                for (int i = 0; i < n; ++i) cur_max = max(cur_max, cur_loads[i]);
                if (cur_max < best_makespan) {
                    best_makespan = cur_max;
                    // сохранить assignment (not kept here to keep code кратким)
                }
                return;
            }
            for (int machine = 0; machine < n; ++machine) {
                cur_loads[machine] += jobs[pos];
                // простая отсечка: если текущая загрузка уже >= лучший, можно всё равно продолжать,
                // но для простоты оставим без отсечек (m small).
                dfs(pos+1);
                cur_loads[machine] -= jobs[pos];
            }
        };
        dfs(0);
        cout << "Optimal (by brute force) makespan = " << best_makespan << "\n";
    } else {
        cout << "Brute-force optimal search skipped: too large search space (n^m > 5e6).\n";
    }

    return 0;
}

