# RPG Game built with pure C++ (To teach OOP)

### [You can find the slides here](Slides/)
### [You can find a Git/Github slides here](Slides/Git+Github/)

## Student Projects:

### 1. Obilet Lite (Ticketing & Reservation System)
[GithubRepo]()

The Concept: A terminal-based booking application where users can view available bus or flight routes, check seat availability, and purchase a ticket for a specific journey.

The OOP Focus: State management and capacity constraints. Students will need to ensure two users cannot book the same seat and that a vehicle's capacity cannot be exceeded.

Core Classes:

    Ticket: Stores passenger name and assigned seat number.

    Trip: Stores destination, departure time, maximum capacity, and a Ticket list of booked passengers.

    Terminal: Stores a collection of available trips and handles the booking logic.

### 2. Spotify Lite (Playlist Manager)
[GithubRepo]()

The Concept: A text-based music library where users can create custom playlists, populate them with their favorite tracks, and simulate playing the audio queue.

The OOP Focus: Students practice putting objects inside other objects and writing loops to iterate through them.

Core Classes:

    Song: Stores title, artist, and duration.

    Playlist: Stores a name and a list of Song. Includes methods to add, remove, and display songs.

    User: Stores a username and manages a collection of created playlists.

### 3. Letterboxd Lite (Movie Rating Hub)
[GithubRepo]()

The Concept: A social logging tool where users can browse a catalog of films, leave a star rating, and write short reviews for the movies they have watched.

The OOP Focus: Data aggregation and basic math within classes. Students will write methods that calculate and update a movie's overall rating dynamically as new reviews are added.

Core Classes:

    Review: Stores the author's name, a text comment, and a rating score (e.g., 1 to 5).

    Movie: Stores title, release year, and a list of Reviews. Includes a method to calculate the average score.

    AppDatabase: Holds the main catalog of movies and handles the user input menu.

### 4. Goodreads Lite (Reading Tracker)
[GithubRepo]()

The Concept: A personal library management tool where a user logs the books they own and tracks their reading progress by sorting them into read and unread categories.

The OOP Focus: Filtering and searching. Students will build methods that parse through a list of objects and return specific subsets based on a boolean flag (read and unread).

Core Classes:

    Book: Stores title, author, and a boolean status tracking whether it has been read.

    Bookshelf: Stores a list of Book and contains methods to toggle a book's status and filter the list.

    Reader: Serves as the user profile that owns and interacts with the bookshelf.
