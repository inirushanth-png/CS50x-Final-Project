-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Check crime scene report 28 july 2025 at Humphrey
SELECT description FROM crime_scene_reports WHERE year = 2025 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
--Check The Interviews that Day
SELECT name, transcript FROM interviews WHERE year = 2025 AND month = 7 AND day = 28;
-- Find Earilest Filght on Next Day From fiftyville
SELECT id, destination_airport_id, hour, minute FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND year = 2025 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1;
-- Find escaped City by early flight id
SELECT city FROM airports WHERE id = 4;
-- Find that excat flight passangers name
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);
-- Find that stealed bakery matching security logs
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2025 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25 AND activity = 'exit');
-- Find that Day Leggett Street Withdraw atm logs by revieweranswer
 SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2025 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'));
-- Matching that day under the 60 seconds phone call records and find the criminal name
  SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2025 AND month = 7 AND day = 28 AND duration < 60);
-- Find accomplice who received the call from Bruce
SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE year = 2025 AND month = 7 AND day = 28 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE name = 'Bruce'));



SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE year = 2025 AND month = 7 AND day = 28 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE name = 'Bruce'));
