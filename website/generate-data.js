const fs = require('fs');
const path = require('path');

const BASE_DIR = path.join(__dirname, '..');

// Define the structure and categories
const categories = {
  'Arrays - Easy': 'practices/Arrays/Easy',
  'Arrays - Medium': 'practices/Arrays/Medium',
  'Sorting I': 'practices/LearnImportantSortingTechniques/sorting-I',
  'Sorting II': 'practices/LearnImportantSortingTechniques/sorting-II',
  'Learning Basics': 'practices/LearningBasic',
  'Patterns': 'practices/Patterns',
  'Self Practices': 'practices/selfPrectices',
  'C++ Working': 'components/CppWorking'
};

function getFiles(dirPath) {
  const fullPath = path.join(BASE_DIR, dirPath);
  if (!fs.existsSync(fullPath)) return [];
  
  return fs.readdirSync(fullPath)
    .filter(file => file.endsWith('.c++') || file.endsWith('.cpp'))
    .filter(file => !file.startsWith('#') && !file.includes('tempCodeRunner'))
    .map(file => {
      const filePath = path.join(fullPath, file);
      const content = fs.readFileSync(filePath, 'utf-8');
      const name = file.replace(/\.(c\+\+|cpp)$/, '').replace(/([A-Z])/g, ' $1').trim();
      return {
        name: name,
        filename: file,
        path: `${dirPath}/${file}`,
        content: content
      };
    });
}

function generateData() {
  const data = {};
  
  for (const [category, dirPath] of Object.entries(categories)) {
    const files = getFiles(dirPath);
    if (files.length > 0) {
      data[category] = files;
    }
  }
  
  return data;
}

const codeData = generateData();

// Generate JavaScript file
const jsContent = `// Auto-generated file - Run 'node generate-data.js' to update
const codeData = ${JSON.stringify(codeData, null, 2)};

export default codeData;
`;

fs.writeFileSync(path.join(__dirname, 'data.js'), jsContent);

console.log('✅ data.js generated successfully!');
console.log('Categories:', Object.keys(codeData));
console.log('Total files:', Object.values(codeData).flat().length);
