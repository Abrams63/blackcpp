# 🎯 Цель MVP

Создать **полностью играбельную одиночную сессию** в терминале,  
с четкой структурой кода, готовой к расширению  
(добавлению мультиплеера и сложных правил).

---

## 🗂️ 1. Структура Проекта (Требование 2)

Самое важное — правильно разделить логику по файлам:

```cpp

/blackjack
│
├── Card.h               // Структуры Suit, Rank и Card
├── Card.cpp             // (Может быть не нужен, если всё в .h)
│
├── /src
│   ├── main.cpp         // Главное Меню (Требование 4)
│   │
│   ├── Deck.h           // Класс Deck (колода)
│   ├── Deck.cpp         // Логика shuffle(), deal()
│   │
│   ├── Player.h         // Классы Hand, Player, Dealer
│   ├── Player.cpp       // addCard(), getTotalValue() (логика Туза)
│   │
│   ├── Game.h           // Класс Game (управление одиночной игрой)
│   ├── Game.cpp         // Основной игровой цикл (game loop)
│   │
│   ├── UI.h             // Отображение ASCII (Требование 1)
│   ├── UI.cpp           // SplashScreen, карты, стол (Требование 1)
│   │
│   ├── Network.h        // Заголовок для TCP-логики (Требование 3)
│   └── Network.cpp      // Клиент/сервер-заглушка для мультиплеера
│
└── Makefile (или CMakeLists.txt) // Сборка проекта
```

--

## 🛠️ 2. Ключевые Компоненты и Фичи

### A. Главное Меню и Запуск (Требования 1, 4)

**`main.cpp`**

- **ASCII-графика**  
  При запуске вызывается `UI::showSplashScreen()`, которая печатает ASCII-арт "BLACKJACK".

- **Главное Меню:**  
  После сплэша появляется меню:

```cpp

1. Одиночная игра
2. Мультиплеер
3. Помощь

```

- `1` → создаёт `Game game;` и вызывает `game.run();`
- `2` → вызывает `Network::startMultiplayer();`
- `3` → вызывает `UI::showHelp();`

---

### B. Ядро Одиночной Игры (MVP)

**Card.h**

```cpp
enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum class Rank { TWO, THREE, ..., KING, ACE };
struct Card { Suit suit; Rank rank; };
```

**Deck.h / Deck.cpp**

```cpp
class Deck {
    std::vector<Card> m_cards;
public:
    Deck();             // Заполняет 52 карты
    void shuffle();     // std::shuffle
    Card deal();        // Возвращает карту
};
```

**Player.h / Player.cpp**

```cpp
class Hand {
    std::vector<Card> m_cards;
public:
    void addCard(Card card);
    int getTotalValue(); // Считает сумму с обработкой Тузов (11→1)
};

class Player {
    Hand m_hand;
};

class Dealer : public Player {}; // Тот же, но с другими правилами
```

**Game.h / Game.cpp**

```cpp
class Game {
    Deck m_deck;
    Player m_player;
    Dealer m_dealer;
public:
    void run();
};
```

**Основной цикл:**

```cpp

1. `m_deck.shuffle();`
2. Сдать по 2 карты игроку и дилеру.
3. Показать стол (`UI::drawTable()`).
4. Ход игрока: `Hit (1)` или `Stand (2)`.
5. Проверить перебор (>21).
6. Ход дилера: добирает до 17.
7. Сравнить очки → объявить победителя.
8. Спросить "Играть снова?".
```

---

### C. Структура для Мультиплеера (Требование 3)

**Network.h / Network.cpp**

```cpp
#include <iostream>
#include "Network.h"

void Network::startMultiplayer() {
    std::cout << "--- Multiplayer Mode ---\n";
    std::cout << "This feature is not yet implemented in the MVP.\n";
    std::cout << "Networking logic will live in Network.cpp\n";
}
```

💡 **Почему так:**
Файл и функция уже есть, меню работает, но TCP-логика реализуется позже
(например, через Asio/Boost.Asio/Sockets).

---

## 🎨 3. ASCII Графика (Требование 1)

**UI.h / UI.cpp**

```cpp
void clearScreen();         // system("cls") / system("clear")
void showSplashScreen();    // ASCII-арт "BLACKJACK"
void showHelp();            // Правила игры
void drawCard(const Card&); // Рисует карту
void drawTable(const Player&, const Dealer&, bool showDealerHoleCard);
```

Функции могут быть `static` или в `namespace UI`.

**Пример карты:**

```cpp
┌─────┐
│ A   │
│  ♥  │
│   A │
└─────┘
```

```cpp
   Player Total: [число]
   Dealer Total: [число]
```

**Функция `drawTable()`:**

- Очищает экран
- Рисует:

  - Руку дилера (если `showDealerHoleCard == false`, вторая карта — `[ ? ]`)
  - Руку игрока
- Показывает:

  ```cpp
   Player Total: [число]
   Dealer Total: [число]
  ```

---

✅ **Итог:**
После реализации этого MVP ты получишь полностью работающую консольную игру Blackjack с чёткой архитектурой и готовыми точками расширения (UI, сеть, правила).

```cpp

```
