# Тестовое задание Blockchain

## About code

Данный проект моделирует работу с блокчейном.

Принцип и структура проекта принципиально приближена к теории блокчейна.

Выполнены задания:
1. Реализовать добавление проверок на отрицательный баланс в методе updateBalance класса Wallet.
2. Реализовать проверку допустимого минимального баланса при отправке транзакции.
3. Добавить метод в Blockchain для вычисления общего количества транзакций и общей суммы.

Пометка по первому заданию: не до конца понятна формулировка "Реализовать добавление проверок". Так же в принципе выглядит так, будто первое задание выполняет почти такую же роль как и второе задание. Также, если следовать теории работы блокчейна, то проверка на отрицательный баланс не должно происходить на стороне кошелька. Данные проверки происходят на стороне самого блокчейна. Также в принципе хранение баланса в кошельке не должно происходить, так как баланс высчитывается динамически, путём анализа всех транзакций, связанных с этим кошельком в блокчейне. Данная проверка реализована в коде, но по поводу её целесообразности я сомневаюсь.