#include "Movement.h"

void Movement::playerPosUpdate(IPlayer& player, I_input& input, float dt) {
    float dx = input.mousePos().x - (player.dstRect().x + player.dstRect().w / 2 );
    float dy = input.mousePos().y - (player.dstRect().y + player.dstRect().h / 2 );

    player.angleVec() = Vector2<float>(dx, dy);
    player.angle() = 90 + (atan2(dy, dx) * 180 / M_PI);

    float distance = sqrt(dx * dx + dy * dy);

    dx /= distance;
    dy /= distance;

    float accelerationX = dx * speed * player.speedMod() * player.directionVec().x / player.mass();
    float accelerationY = dy * speed * player.speedMod() * player.directionVec().y / player.mass();

    float frictionX = -player.deacelleration() * player.velocity().x * player.speedMod();
    float frictionY = -player.deacelleration() * player.velocity().y * player.speedMod();
    
    player.velocity().x += (accelerationX + frictionX) * dt;
    player.velocity().y += (accelerationY + frictionY) * dt;

    player.dstRect().x += player.velocity().x * dt;
    player.dstRect().y += player.velocity().y * dt;
}

void Movement::playerRotUpdate(IPlayer& player, I_input& input, float dt) {
    float dx = input.mousePos().x - (player.dstRect().x + player.dstRect().w / 2);
    float dy = input.mousePos().y - (player.dstRect().y + player.dstRect().h / 2);
    
    float distance = sqrt(dx * dx + dy * dy);
    dx /= distance;
    dy /= distance;

    float angle = atan2(dy, dx);

    if (input.pressedD()) {
        float accelAngle = angle + M_PI / 2.0f;
        float accelerationX = -0.5f * speed * player.speedMod() / player.mass() * cos(accelAngle);
        float accelerationY = -0.5f * speed * player.speedMod() / player.mass() * sin(accelAngle);
        player.velocity().x += accelerationX * dt;
        player.velocity().y += accelerationY * dt;
    }

    if (input.pressedA()) {
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

    player.dstRect().x += player.velocity().x * dt;
    player.dstRect().y += player.velocity().y * dt;
}
