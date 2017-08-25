# netfilter_test
## Site Blocking using iptables, NFQUEUE

### 설명

gilgil 멘토님의 iptables 강의 과제입니다.  
현재 대상 사이트 (hxxp: avnana. com) 하나만을 차단하는 수준으로 구현되어 있으며, 패킷 정보를 iptables의 NFQUEUE에서 읽어와 위 문자열을 확인합니다.

### 사용법

1. `sudo iptables -A OUTPUT -p tcp -j NFQUEUE`
2. `sudo ./nfqnl_test`

### To Do

1. 현재 Host를 확인하는 것이 아닌 단순히 대상 사이트 주소 문자열이 있는지만을 확인합니다. 물론 그렇고 그런 사이트가 Referer로 설정되거나 다른 필드로 들어가게 될 일은 거의 없겠지만(웃음) 수정할 예정입니다. 사실 이건 좀 많이 생각했습니다만, Host: 문자열까지 포함하기에는 무언가 유연성이 떨어지는 것 같아서 일단은 이렇게 구현했습니다.
2. Aho-Corasick을 이용하여 사이트들의 Graph를 만들고 매칭하는 매커니즘을 (시간이 된다면) 구현할 예정입니다.
