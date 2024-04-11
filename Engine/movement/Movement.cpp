#include "Movement.h"

void Movement::playerPosUpdate(IPlayer& player, I_input& input, IBackground &back, float dt) {
    float dx = input.mousePos().x - (player.playerDstRect().x + player.playerDstRect().w / 2 );
    float dy = input.mousePos().y - (player.playerDstRect().y + player.playerDstRect().h / 2 );

    player.angleVec() = Vector2<float>(dx, dy);
    player.angle() = 90 + (atan2(dy, dx) * 180 / M_PI);

    float distance = sqrt(dx * dx + dy * dy);

        dx /= distance;
        dy /= distance;

        int accelerationX = dx * speed * player.speedMod() * player.directionVec().x / player.mass();
        int accelerationY = dy * speed * player.speedMod() * player.directionVec().y / player.mass();

        float frictionX = -player.deacelleration() * player.velocity().x * player.speedMod();
        float frictionY = -player.deacelleration() * player.velocity().y * player.speedMod();
        
        player.velocity().x += (accelerationX + frictionX) * dt;
        player.velocity().y += (accelerationY + frictionY) * dt;

        back.rect().x += (player.velocity().x * dt);
        back.rect().y += (player.velocity().y * dt);
}

void Movement::playerRotUpdate(IPlayer& player, I_input& input, IBackground &back, float dt) {
    float dx = input.mousePos().x - (player.playerDstRect().x + player.playerDstRect().w / 2);
    float dy = input.mousePos().y - (player.playerDstRect().y + player.playerDstRect().h / 2);
    
    float distance = sqrt(dx * dx + dy * dy);
        dx /= distance;
        dy /= distance;

        float angle = atan2(dy, dx);

        if (input.pressedA()) {
            float accelAngle = angle + M_PI / 2.0f;
            float accelerationX = -0.5f * speed * player.speedMod() / player.mass() * cos(accelAngle);
            float accelerationY = -0.5f * speed * player.speedMod() / player.mass() * sin(accelAngle);
            player.velocity().x += accelerationX * dt;
            player.velocity().y += accelerationY * dt;
        }

        if (input.pressedD()) {
            float accelAngle = angle - M_PI / 2.0f;
            float accelerationX = -0.5f * speed * player.speedMod() / player.mass() * cos(accelAngle);
            float accelerationY = -0.5f * speed * player.speedMod() / player.mass() * sin(accelAngle);
            player.velocity().x += accelerationX * dt;
            player.velocity().y += accelerationY * dt;
        }

        float frictionX = -player.deacelleration() * player.velocity().x * player.speedMod();
        float frictionY = -player.deacelleration() * player.velocity().y * player.speedMod();
        
        player.velocity().x += frictionX * dt;
        player.velocity().y += frictionY * dt;

        back.rect().x += player.velocity().x * dt;
        back.rect().y += player.velocity().y * dt;
}
