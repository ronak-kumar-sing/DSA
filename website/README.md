# DSA Code Library - Frontend

A beautiful, responsive web interface to browse and view your Data Structures & Algorithms code collection.

## Features

- 📚 **Organized by Category** - Arrays, Sorting, Basics, and more
- 🔍 **Search Functionality** - Quickly find files by name
- 🏷️ **Filter Tags** - Filter by difficulty (Easy/Medium) or type (Sorting)
- 🎨 **Syntax Highlighting** - Beautiful code display with Prism.js
- 📋 **Copy to Clipboard** - One-click code copying
- 📱 **Responsive Design** - Works on desktop and mobile
- 🌙 **Dark Theme** - Easy on the eyes

## Quick Start

### Option 1: Using Python (Recommended)

```bash
cd website
python3 -m http.server 8080
```

Then open http://localhost:8080 in your browser.

### Option 2: Using Node.js

```bash
cd website
npx serve
```

### Option 3: Using VS Code Live Server

1. Install the "Live Server" extension in VS Code
2. Right-click on `index.html` and select "Open with Live Server"

## Updating the Code Data

When you add new code files to your DSA collection, regenerate the data file:

```bash
cd website
node generate-data.js
```

This will scan all `.c++` and `.cpp` files in your practices and components folders.

## File Structure

```
website/
├── index.html          # Main frontend file
├── data.js             # Generated code data (auto-generated)
├── generate-data.js    # Script to generate data.js
└── README.md           # This file
```

## Hosting Online

### GitHub Pages

1. Push your repository to GitHub
2. Go to Settings > Pages
3. Select the `website` folder as source
4. Your site will be live at `https://username.github.io/DSA/website/`

### Netlify / Vercel

1. Connect your GitHub repository
2. Set the build directory to `website/`
3. Deploy!

## Technologies Used

- HTML5, CSS3, JavaScript (ES6+)
- [Prism.js](https://prismjs.com/) - Syntax highlighting
- [Google Fonts](https://fonts.google.com/) - Inter & Fira Code fonts

## Customization

### Adding New Categories

Edit the `categories` object in `generate-data.js`:

```javascript
const categories = {
  'Arrays - Easy': 'practices/Arrays/Easy',
  'Your New Category': 'path/to/folder',
  // ...
};
```

### Changing Theme Colors

Edit the CSS variables in `index.html`:

```css
:root {
  --bg-primary: #0d1117;
  --accent-color: #58a6ff;
  /* ... */
}
```

---

Made with ❤️ for DSA learners
