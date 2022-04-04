import java.util.Comparator;
import java.util.PriorityQueue;

class Printer {
	public static void main(String[] args) {
		int[] array = { 2, 1, 3, 2 };
		int a = solution(array, 2);
		System.out.println(a);
	}

	public static int solution(int[] priorities, int location) {
		int answer = 1;
		PriorityQueue<Integer> queue = new PriorityQueue<Integer>(Comparator.reverseOrder());
		for (int n : priorities)
			queue.offer(n); // add(n)

		while (!queue.isEmpty()) {
			for (int i = 0; i < priorities.length; i++) {
				if (queue.peek() == priorities[i]) { // peek==검사
					if (location == i)
						return answer;
					answer++;	
					queue.poll(); //remove 
				}
			}
		}

		return answer;
	}
}
