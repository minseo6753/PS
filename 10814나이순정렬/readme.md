### STL sort의 compare함수는 strict weak odering을 만족해야 한다. 
여기에는 compare(a,b)가 true면 compare(b,a)는 false여야 한다는 규칙이 있다.
즉 어떤 원소가 앞이고 어떤 원소가 뒤인지 결정해줘야 하는데 
만약 값이 같을때 compare가 true를 반환해버리면 둘 중 어떤 게 앞이고 뒤인지 결정을 못하게 되는 것이다.

나는 처음에 나이가 같을 때 순서를 유지하게 하기 위해서 compare함수에서 return a.first<=b.first 를 했다.
이러니 strict weak odering 에 위반하여 에러가 났다.


### stable_sort
sort는 값이 같은 원소의 순서를 보장해주지 않는다. 즉 뒤섞일 수 있다.
이를 보장해주는 게 stable_sort이다.
사용법은 sort와 같다.


### sort pair
pair를 sort하게 되면 첫번째 원소를 기준으로 정렬하고 만약 첫번째 원소의 값이 같으면 두번째 원소를 기준으로 정렬한다.

이 코드에서는 두번째 원소를 고려하지 않도록 해야하므로 compare함수를 디폴트가 아닌 새로 정의해서 써야 한다.