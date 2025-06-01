import { initNavigation } from './navigation.js';
import { loadHomeContent } from './home.js';
import { loadFeaturesContent } from './features.js';
import { loadGuideContent } from './guide.js';
import { loadAboutContent } from './about.js';
import { loadAddContent } from './add.js';
import { loadGithubContent } from './github.js';

function handleRoute() {
    const hash = window.location.hash.substring(1) || 'home';
    const contentElement = document.getElementById('content');
    contentElement.innerHTML = '';

    switch(hash) {
        case 'features':
            loadFeaturesContent();
            break;
        case 'guide':
            loadGuideContent();
            break;
        case 'about':
            loadAboutContent();
            break;
        case 'add':
            loadAddContent();
            break;
        case 'github':
            loadGithubContent();
            break;
        default:
            loadHomeContent();
    }
}

document.addEventListener('DOMContentLoaded', () => {
    initNavigation();
    handleRoute();
    
    window.addEventListener('hashchange', handleRoute);
});
