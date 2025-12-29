class Player : public Entity {
    int health;
    int attackDamage;

public:
    void restoreHealth(int heal);
    void takeDamage(int damage);
}
